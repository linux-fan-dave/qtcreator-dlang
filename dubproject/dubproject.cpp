#include "dubproject.h"
#include "dubprojectconstants.h"
#include "dubprojectmanager.h"
#include "dubfile.h"
#include "dubprojectprojectnode.h"
#include "d_initializer.h"

namespace DubProject {

DubProject::DubProject(Internal::DubProjectManager *manager, const Utils::FileName &filename)
{
    static Internal::D_Initializer init;
    m_dproject = Internal::DProject::create();
    setId(Constants::DUBPROJECT_ID);
    setProjectManager(manager);
    setDocument(new Internal::DubFile(filename));
    setRootProjectNode(new Internal::DubProjectProjectNode(filename));
    m_dproject->load(filename.parentDir().toString().toUtf8().constData(), [](bool succeded, const char* errorString) {
        qDebug() << "load succeded" << succeded << "errorString" << errorString;
    });
}

QString DubProject::displayName() const
{
    return QString("xyz");
}

QStringList DubProject::files(ProjectExplorer::Project::FilesMode /*fileMode*/) const
{
    return QStringList();
}

}


