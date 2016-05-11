#ifndef DUBPROJECT_H
#define DUBPROJECT_H


#include <projectexplorer/project.h>

namespace DubProject {
namespace Internal {
class DubProjectManager;
}

class DubProject : public ProjectExplorer::Project
{
public:
    DubProject(Internal::DubProjectManager *manager, const Utils::FileName &filename);

    // Project interface
public:
    QString displayName() const override;
    QStringList files(FilesMode fileMode) const override;
};

}

#endif // DUBPROJECT_H
