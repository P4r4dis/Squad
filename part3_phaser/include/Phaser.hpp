#ifndef     __PHASER__
#   define  __PHASER__

#include <string>
#include "Sounds.hpp"

class   Phaser
{
    public:
        enum                AmmoType
        {
            REGULAR,
            PLASMA,
            ROCKET
        };

        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~Phaser(void);

        int                 getCurrentAmmos(void);
        int                 getEmpty(void)  const;
        AmmoType            getAmmoType(void);
        void                fire(void);
    private:
        static const int    Empty = 0;
        int                 _maxAmmo;
        AmmoType            _type;
};


#endif //   !__PHASER__