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
};


#endif //   !__SKAT__