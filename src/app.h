#ifndef APP_H
#define APP_H

#include "smart_ptr.hpp"

#include <string>

#include "setting.h"
#include "server.h"
#include "thread/bidirectional_communicator.h"
#include "scheduler/app_scheduler.h"
#include "router/router.h"
#include "error/error_handle_router.h"
#include "actor/actor_manager.h"
#include "cluster/cluster.h"
#include "main_loop.h"
#include "db/voltdb/voltdb_processor.h"

#include "error/internal/error_handle_route_map.h"
#include "router/internal/route_map.h"

struct ArgsInfo
{
    std::string config_file;

    ArgsInfo()
    {
        //
    }
};

class App
{
public:
    int start(int argc, char** argv);
    
    Server::ptr getServer() const
    {
        return server;
    }

private:
    void parseArgs(int argc, char** argv, ArgsInfo& args);
    Setting::ptr initSettings(ArgsInfo& args);
    
    void stopApp();
    
    void setupTcpServer(Setting::const_ptr setting);
    void setupUdpServer(Setting::const_ptr setting);

    void initRandomGenerator(Setting::const_ptr setting);
    void initThreadPool(Setting::const_ptr setting);
    void initScheduler(Setting::const_ptr setting);
    void initRouter(Setting::const_ptr setting);
    void initErrorHandleRouter(Setting::const_ptr setting);
    void initActorManager(Setting::const_ptr setting);
    void initMainLoop(Setting::const_ptr setting);
    void initIOThread(Setting::const_ptr setting);
    void initNodeServer(Setting::const_ptr setting);
    void initKeyValueCache(Setting::const_ptr setting);

    void initVoltdbThread(Setting::const_ptr setting);
    void initRedisClient(Setting::const_ptr setting);

    void setupCluster(Setting::const_ptr setting);
    
    Server::ptr server;
    BidirectionalCommunicator::ptr task_comm;

    AppScheduler::ptr app_scheduler;
    ActorManager::ptr user_actor_manager;
    ActorManager::ptr up_actor_manager;
    ActorManager::ptr down_actor_manager;
    Cluster::ptr cluster;

    MainLoop::ptr main_loop;
    VoltdbProcessor::ptr v_processor;
    Router::ptr user_router;
    Router::ptr system_router;
    ErrorHandleRouter::ptr err_handle_router;

    RouteMap::ptr user_route_map;
    RouteMap::ptr system_route_map;

    ErrorHandleRouteMap::ptr err_handle_route_map;
    std::vector<TaskDispatcher::ptr> io_threads;
};

#endif
