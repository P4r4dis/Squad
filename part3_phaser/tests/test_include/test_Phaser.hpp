#ifndef     __TEST_PHASER__
#   define  __TEST_PHASER__

#include <string>
#include <vector>
#include "test_sounds.hpp"

void    redirect_all_stdout(void);

class                           Phaser
{
    public:

        enum                    AmmoType
        {
            REGULAR,
            PLASMA,
            ROCKET
        };

        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~Phaser(void);
        int                             getCurrentAmmos(void);
        int                             getMaxAmmos(void);
        int                             getEmpty(void)  const;
        AmmoType                        getAmmoType(void);
        AmmoType                        getDefaultAmmoType(void);
        void                            fire(void);
        void                            ejectClip(void);
        void                            changeType(AmmoType newType);
        void                            reload(void);
        std::vector<Phaser::AmmoType>   getMagazine(void);

    private:
        int                             _maxAmmo;
        AmmoType                        _type;
        static const int                Empty = 0;
        int                             _currentAmmo;
        std::vector<AmmoType>           _magazine;

};

#endif //   !__TEST_PHASER__