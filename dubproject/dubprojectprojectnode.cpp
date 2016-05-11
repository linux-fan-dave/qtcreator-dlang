#include "dubprojectprojectnode.h"

namespace DubProject {
namespace Internal {

DubProjectProjectNode::DubProjectProjectNode(const Utils::FileName &fileName)
    :ProjectExplorer::ProjectNode(fileName)
{
}

QString DubProjectProjectNode::displayName() const
{
    return QLatin1Literal("xyz");
}

}
}


