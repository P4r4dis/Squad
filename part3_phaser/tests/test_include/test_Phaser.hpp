#ifndef     __TEST_PHASER__
#   define  __TEST_PHASER__

#include <string>
#include <memory>

void    redirect_all_stdout(void);

class   Phaser
{
    private:

    public:
        Phaser();
        ~Phaser(void);
};

#endif //   !__TEST_PHASER__