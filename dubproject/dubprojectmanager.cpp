#include "dubprojectmanager.h"
#include <utils/fileutils.h>
#include <QFileInfo>
#include "dubproject.h"
#include "dubprojectconstants.h"

namespace DubProject {
namespace Internal {

DubProjectManager::DubProjectManager() : ProjectExplorer::IProjectManager()
{

}

QString DubProjectManager::mimeType() const
{
    return QLatin1Literal(Constants::DUBPROJECT_MIMETYPE);
}

ProjectExplorer::Project *DubProjectManager::openProject(const QString &fileName, QString *errorString)
{
    Utils::FileName file = Utils::FileName::fromString(fileName);
    if (!file.toFileInfo().isFile()) {
        if (errorString)
            *errorString = tr("Failed opening project \"%1\": Project is not a file")
                .arg(file.toUserOutput());
        return 0;
    }

    return new DubProject(this, file);
}

}
}


