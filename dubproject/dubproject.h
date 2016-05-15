#ifndef DUBPROJECT_H
#define DUBPROJECT_H


#include <projectexplorer/project.h>
#include "dproject.h"

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
private:
    Internal::DProjectPtr m_dproject;
};

}

#endif // DUBPROJECT_H
