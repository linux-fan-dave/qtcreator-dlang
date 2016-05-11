#ifndef DUBFILE_H
#define DUBFILE_H

#include <coreplugin/idocument.h>

namespace DubProject {
namespace Internal {

class DubFile: public Core::IDocument
{
public:
    DubFile(const Utils::FileName &fileName);

    ReloadBehavior reloadBehavior(ChangeTrigger state, ChangeType type) const override;
};

}
}

#endif // DUBFILE_H
