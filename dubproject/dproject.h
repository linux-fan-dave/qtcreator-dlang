#ifndef DPROJECT_H
#define DPROJECT_H

#include <QSharedPointer>

namespace DubProject {
namespace Internal {

class DProject;
typedef QSharedPointer<DProject> DProjectPtr;

class DProject {
public:
    DProject() = delete;
    static DProjectPtr create();

    virtual void load();
    virtual void reload();
};

}
}
#endif // DPROJECT_H
