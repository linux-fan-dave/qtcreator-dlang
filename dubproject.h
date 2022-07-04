#ifndef DUBPROJECTPLUGIN_H
#define DUBPROJECTPLUGIN_H

#include "dubproject_global.h"

#include <extensionsystem/iplugin.h>

namespace DubProject {
namespace Internal {

class DubProjectPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "DubProject.json")

public:
    DubProjectPlugin();
    ~DubProjectPlugin() override;

    bool initialize(const QStringList &arguments, QString *errorString) override;
    void extensionsInitialized() override;
    ShutdownFlag aboutToShutdown() override;

private:
    void triggerAction();
};

} // namespace Internal
} // namespace DubProject

#endif // DUBPROJECTPLUGIN_H
