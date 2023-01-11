#ifndef     __TEST_SKAT__
#   define  __TEST_SKAT__

#include <string>


void    redirect_all_stdout(void);

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
        const std::string       &name(void);
};

#endif //   !__TEST_SKAT__