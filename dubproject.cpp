#include "dubproject.h"
#include "dubprojectconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>
#include <iostream>

namespace DubProject {
namespace Internal {

class DProject;
DProject* CreateDProject();
void ReleaseDProject(DProject* inst);

class DProject
{
  public:
    typedef void(*ErrorHandler)(bool succeeded, void* userData, const char* error_description);
    virtual void load(const char* path, void* userData, ErrorHandler eh);
    virtual void reload(void* userData, ErrorHandler eh);
};

extern "C" int rt_init();
DubProjectPlugin::DubProjectPlugin()
{
    rt_init();
    // Create your members
    std::cout << "create DProject" << std::endl;
    DProject* dp = CreateDProject();
    std::cout << "create DProject finished" << std::endl;
    std::cout << "load DProject" << std::endl;
    dp->load("/home/david/DubProject/dub_cpp/", this, [](bool succeeded, void* userData, const char* error_description){
        std::cout << "load DProject result here " << error_description << std::endl;
    });
    std::cout << "load DProject finished" << std::endl;
}

DubProjectPlugin::~DubProjectPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool DubProjectPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    auto action = new QAction(tr("DubProject Action"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, &QAction::triggered, this, &DubProjectPlugin::triggerAction);

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("DubProject"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    return true;
}

void DubProjectPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag DubProjectPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void DubProjectPlugin::triggerAction()
{
    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action Triggered"),
                             tr("This is an action from DubProject."));
}

} // namespace Internal
} // namespace DubProject
