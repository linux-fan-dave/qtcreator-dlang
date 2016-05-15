#include "dubproject.h"
#include "dubprojectconstants.h"
#include "dubprojectmanager.h"
#include "dubfile.h"
#include "dubprojectprojectnode.h"

namespace DubProject {

DubProject::DubProject(Internal::DubProjectManager *manager, const Utils::FileName &filename)
{
    setId(Constants::DUBPROJECT_ID);
    setProjectManager(manager);
    setDocument(new Internal::DubFile(filename));
    setRootProjectNode(new Internal::DubProjectProjectNode(filename));
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


