#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class Singleton {
    public:
        /// This method gets one and only one instance of a UT_Singleton derived class
        /** This is a method that does so
          * much that I must write an epic 
          * novel just to describe how much
          * it truly does. */
        static T& getInstance() {
            static T instance;
            return instance;
        }

    protected:
        Singleton() {}
        ~Singleton() {}

    public:
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(Singleton&&) = delete;

        //Singleton(const Singleton &) = delete;
        //Singleton& operator=(const Singleton &) = delete;

};

#endif // SINGLETON_H
