#ifndef     __SKAT__
#   define  __SKAT__

#include <string>
class   Skat
{
    private:
        std::string             _name;
        int                     _stimPaks;
    public:
        Skat(const std::string& name = "bob", int stimPaks = 15);
        ~Skat();

        int&                    stimPaks(void);
        const std::string       &name(void);
        void                    shareStimPaks(int number, int &stock);
        void                    addStimPaks(unsigned int number);

};


#endif //   !__SKAT__