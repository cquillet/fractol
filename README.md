# fractol

**You will need to download the [`libs`](https://github.com/cquillet/libs) project in the same directory you will clone `fractol` to run it**

This is a program to draw fractals

*usage:* `fractol (mandel[brot] | julia | burning | newton)`

Available fractals/sets are :
* [Madelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set) : { c ∈ ℂ, ∀n ∈ ℕ, |z<sub>n</sub>| ≤ 2 } , _with_ z<sub>n+1</sub> = z<sub>n</sub><sup>2</sup> + c , z<sub>0</sub> = 0
* [Julia](https://en.wikipedia.org/wiki/Julia_set) : { z<sub>0</sub> ∈ ℂ, ∀n ∈ ℕ, |z<sub>n</sub>| ≤ 2 } , _with_ z<sub>n+1</sub> = z<sub>n</sub><sup>d</sup> + c , value of _c_ can be changed by moving the mouse which animates the fractal (`space bar` to play/pause), the power _d_ of the formula can be changed with the keys `[` and `]` (multi-Julia)
* [Burning ship](https://en.wikipedia.org/wiki/Burning_Ship_fractal) : { c ∈ ℂ, ∀n ∈ ℕ, |z<sub>n</sub>| ≤ 2 } , _with_ z<sub>n+1</sub> = ( |ℜe(z<sub>n</sub>)| + ⅈ |ℑm(z<sub>n</sub>)| )<sup>2</sup> + c , z<sub>0</sub> = 0
* [Newton](https://en.wikipedia.org/wiki/Newton_fractal) :  { z<sub>0</sub> ∈ ℂ, ∀n ∈ ℕ, |z<sub>n</sub>| ≤ 2 } , for a fixed polynomial _P_ ∈ ℂ[X] , _with_ z<sub>n+1</sub> = z<sub>n</sub> - P(z<sub>n</sub>) / P'(z<sub>n</sub>), the used polynomial can be changed with the keys `[` and `]`

You can draw a box (*click and drag*) in order to zoom in (*left click*) or out (*right click*) 

During the execution, press `H` to show a little help


#### Example of the zoombox in Julia set:
>`fractol julia`
>
>![julia with zoombox](https://raw.githubusercontent.com/cquillet/stuff/master/img/fractol.png)
