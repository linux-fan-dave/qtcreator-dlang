#include "dubprojectmanager.h"
#include <QDebug>

namespace DubProject {
namespace Internal {

DubProjectManager::DubProjectManager() : ProjectExplorer::IProjectManager()
{

}

QString DubProjectManager::mimeType() const
{
    return QString("text/x-dub-project");
}

ProjectExplorer::Project *DubProjectManager::openProject(const QString &fileName, QString *errorString)
{
    Q_UNUSED(errorString)

    qDebug() << "DubProjectManager::openProject: filename <" <<  fileName << ">";
    return nullptr;
}

}
}


