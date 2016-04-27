#ifndef DUBPROJECTMANAGER_H
#define DUBPROJECTMANAGER_H

#include <projectexplorer/iprojectmanager.h>

namespace DubProject {
namespace Internal {

class DubProjectManager : public ProjectExplorer::IProjectManager
{
    Q_OBJECT
public:
    explicit DubProjectManager();
    QString mimeType() const override;
    ProjectExplorer::Project *openProject(const QString &fileName, QString *errorString) override;

signals:

public slots:
};

}
}
#endif // DUBPROJECTMANAGER_H
