#ifndef USER_RECORD_REDIS_H
#define USER_RECORD_REDIS_H

#include <string>
#include <functional>

#include "fw_env.h"
#include "redisclient.h"

class UserRecordRedis
{
public:
    static UserRecordRedis* getInstance();

    void add(const std::string& name,
        std::function<void(const RedisValue&)> result_callback);

private:
    UserRecordRedis();
};

#endif
