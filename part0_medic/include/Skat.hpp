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

        const std::string&      getName(void);
        int                     getStimPaks(void);
        int&                    stimPaks(void);
};


#endif //   !__SKAT__