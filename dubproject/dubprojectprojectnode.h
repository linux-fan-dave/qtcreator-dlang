#ifndef DUBPROJECTPROJECTNODE_H
#define DUBPROJECTPROJECTNODE_H

#include <projectexplorer/projectnodes.h>

namespace DubProject {
namespace Internal {

class DubProjectProjectNode : public ProjectExplorer::ProjectNode
{
public:
    DubProjectProjectNode(const Utils::FileName &fileName);

    QString displayName() const override;
};

}
}

#endif // DUBPROJECTPROJECTNODE_H
