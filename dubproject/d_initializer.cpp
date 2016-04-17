#include "d_initializer.h"

extern "C" int rt_init();
extern "C" int rt_term();

namespace DubProject {
namespace Internal {

D_Initializer::D_Initializer()
{
    rt_init();
}

D_Initializer::~D_Initializer()
{
    rt_term();
}

}
}
