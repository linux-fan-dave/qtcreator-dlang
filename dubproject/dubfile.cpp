#include "dubfile.h"
#include "dubprojectconstants.h"
#include <coreplugin/id.h>

namespace DubProject {
namespace Internal {

DubFile::DubFile(const Utils::FileName &fileName)
{
    setId(Core::Id(Constants::DUBPROJECTFILE_ID));
    setMimeType(QLatin1String(Constants::DUBPROJECT_MIMETYPE));
    setFilePath(fileName);
}

Core::IDocument::ReloadBehavior DubFile::reloadBehavior(Core::IDocument::ChangeTrigger state, Core::IDocument::ChangeType type) const
{
    return BehaviorSilent;
}

}
}
