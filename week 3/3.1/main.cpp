#include "hwlib.hpp"
#include "cordinates.hpp"

int main( void ){
    auto scl = hwlib::target::pin_oc( hwlib::target::pins::scl );
    auto sda = hwlib::target::pin_oc( hwlib::target::pins::sda );

    auto i2c = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );

    auto display = hwlib::glcd_oled(i2c, 0x3C);

    auto min_button = hwlib::target::pin_in(hwlib::target::pins::d13);
    auto hour_button = hwlib::target::pin_in(hwlib::target::pins::d12);


    display.clear();

    constexpr auto cos_s = lookup<360, int, 30>(scaled_cos_from_degrees);
    constexpr auto sin_s = lookup<360, int, 30>(scaled_sine_from_degrees);

    constexpr auto cos_m = lookup<360, int, 20>(scaled_cos_from_degrees);
    constexpr auto sin_m = lookup<360, int, 20>(scaled_sine_from_degrees);

    constexpr auto cos_h = lookup<360, int, 15>(scaled_cos_from_degrees);
    constexpr auto sin_h = lookup<360, int, 15>(scaled_sine_from_degrees);

    unsigned int seconds;

    for(;;){
        for(int i = 0; i < 360; i = i + 30){
            for(int j = 0; j < 360; j = j + 6){
                for(int k = 0; k < 360; k = k + 6){
                    seconds = hwlib::now_us();

                    display.clear();
                    auto sechand = hwlib::line(hwlib::xy(32, 32), hwlib::xy((cos_s.get(k) + 2), (sin_s.get(k) + 2)));
                    auto minhand = hwlib::line(hwlib::xy(32, 32), hwlib::xy((cos_m.get(j) + 12), (sin_m.get(j) + 12)));
                    auto hourhand = hwlib::line(hwlib::xy(32, 32), hwlib::xy((cos_h.get(i) + 17), (sin_h.get(i) + 17)));
                    for(int l = 0; l < 360; l = l + 30){
                            hwlib::circle circle(hwlib::xy(((cos_s.get(l) + 2 )), (sin_s.get(l) + 2)), 1);
                            circle.draw(display);
                        }
                    if(!min_button.read()){
                        j = j + 6;
                    }
                    if(!hour_button.read()){
                        i = i + 30;
                    }
                    minhand.draw(display);
                    sechand.draw(display);
                    hourhand.draw(display);
                    display.flush();
                    while( hwlib::now_us() < (seconds + 1000000)){}

                }
            }



        }
    }


}
