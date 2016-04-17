#ifndef DUBPROJECT_H
#define DUBPROJECT_H

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
    ~DubProjectPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private slots:
    void triggerAction();
};

} // namespace Internal
} // namespace DubProject

#endif // DUBPROJECT_H
