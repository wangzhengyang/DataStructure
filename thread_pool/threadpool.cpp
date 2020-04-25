#include "threadpool.h"

void *ThreadPool::ThreadPool_Cycle(void *data)
{
    ThreadPool *tp = (ThreadPool*)data;
    int err;
    sigset_t set;
    ThreadTask *ptask;

    /*TODO*/

    sigfillset(&set);

    sigdelset(&set, SIGILL);
    sigdelset(&set, SIGFPE);
    sigdelset(&set, SIGSEGV);
    sigdelset(&set, SIGBUS);

    err = pthread_sigmask(SIG_BLOCK, &set, NULL);
    if(err != 0){
        /*TODO*/
        return NULL;
    }

    for(;;){
        if(ThreadMutex::ThreadMutex_Lock(&tp->mtx) != 0){
            return NULL;
        }

        while(tp->queue.empty()){
            if(ThreadCond::ThreadCond_Wait(&tp->cond, &tp->mtx) != 0){
                ThreadMutex::ThreadMutex_Unlock(&tp->mtx);
                return NULL;
            }
        }
        ptask = tp->queue.front();
        tp->queue.pop();
        tp->waiting--;
        
        if(ThreadMutex::ThreadMutex_Unlock(&tp->mtx) != 0){
            return NULL;
        }

        ptask->run();
        
        if(ptask != NULL)
            delete (ptask);
        
    }

}

int ThreadPool::ThreadPool_Init(ThreadPool *pool)
{
    int err;
    pthread_t tid;
    pthread_attr_t attr;
    int n;

    if(ThreadMutex::ThreadMutex_Init(&pool->mtx) != 0)
        return -1;

    if(ThreadCond::ThreadCond_Init(&pool->cond) != 0){
        ThreadMutex::ThreadMutex_Destroy(&pool->mtx);
        return -1;
    }

    err = pthread_attr_init(&attr);
    if(err != 0){
        /*TODO*/
        return -1;
    }

    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if(err != 0){
        /*TODO*/
        return -1;
    }

    for(n = 0; n < pool->threads; n++){
        err = pthread_create(&tid, &attr, ThreadPool::ThreadPool_Cycle, pool);
        if(err != 0){
            /*TODO*/
            return -1;
        }
    } 
    
    pthread_attr_destroy(&attr);
    return 0;
}

int ThreadPool::ThreadPool_Post(ThreadPool *pool, ThreadTask *task)
{
    if(ThreadMutex::ThreadMutex_Lock(&pool->mtx) != 0){
        return -1;
    }

    if(pool->waiting >= pool->maxqueue){
        ThreadMutex::ThreadMutex_Unlock(&pool->mtx);
        /*TODO*/
        return -1;
    }

    if(ThreadCond::ThreadCond_Signal(&pool->cond) != 0){
        ThreadMutex::ThreadMutex_Unlock(&pool->mtx);
        return -1;
    }

    pool->queue.push(task);
    pool->waiting++;

    ThreadMutex::ThreadMutex_Unlock(&pool->mtx);
    /*TODO*/
    return 0;
}

void ThreadPool::ThreadPool_exit_handler(void *data)
{
    int *lock = (int*)data;
    *lock = 0;
    
    pthread_exit(0);
}

void ThreadPool::ThreadPool_Destroy(ThreadPool *pool)
{
    int n;
    
}
