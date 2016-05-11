#include "dubprojectplugin.h"
#include "dubprojectconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <utils/mimetypes/mimedatabase.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>


#include <QtPlugin>
#include "d_initializer.h"

#include "dubprojectmanager.h"

using namespace DubProject::Internal;

class B {
public:
   virtual int count();
};

B* CreateB();

DubProjectPlugin::DubProjectPlugin()
{
//    static D_Initializer init;

//    B* b = CreateB();
//    int i = b->count();
//    QMessageBox msgBox;
//    msgBox.setText(QString("D returned %1").arg(i));
//    msgBox.exec();

    // Create your members
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

    Utils::MimeDatabase::addMimeTypes(":DubProject.mimetypes.xml");
    addAutoReleasedObject(new DubProjectManager);



//    QAction *action = new QAction(tr("DubProject action"), this);
//    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
//                                                             Core::Context(Core::Constants::C_GLOBAL));
//    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
//    connect(action, SIGNAL(triggered()), this, SLOT(triggerAction()));

//    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
//    menu->menu()->setTitle(tr("DubProject"));
//    menu->addAction(cmd);
//    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

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

//void DubProjectPlugin::triggerAction()
//{
//    QMessageBox::information(Core::ICore::mainWindow(),
//                             tr("Action triggered"),
//                             tr("This is an action from DubProject."));
//}
