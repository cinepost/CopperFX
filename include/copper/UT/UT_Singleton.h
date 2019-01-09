#ifndef __UT_Singleton_h__
#define __UT_Singleton_h__

template <typename T>
class UT_Singleton
{
    public:
        static T& getInstance()
        {
            static T instance;
            return instance;
        }

    protected:
        UT_Singleton() {}
        ~UT_Singleton() {}

    public:
        UT_Singleton(UT_Singleton const &) = delete;
        void operator=(UT_Singleton const &) = delete;

};

#endif // __UT_Singleton_h__
