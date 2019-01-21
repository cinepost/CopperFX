#ifndef UT_SINGLETON_H
#define UT_SINGLETON_H

template <typename T>
class UT_Singleton
{
    public:
        /// This method gets one and only one instance of a UT_Singleton derived class
        /** This is a method that does so
          * much that I must write an epic 
          * novel just to describe how much
          * it truly does. */
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

#endif // UT_SINGLETON_H
