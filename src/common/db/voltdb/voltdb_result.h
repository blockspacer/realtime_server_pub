#ifdef USE_VOLTDB

#ifndef VOLTDB_RESULT_H
#define VOLTDB_RESULT_H

#include "voltdb.h"

BEGIN_NS

struct VoltdbResult
{
    voltdb::InvocationResponse* res;

    VoltdbResult()
    {
        res = NULL;
    }
};

END_NS

#endif

#endif
