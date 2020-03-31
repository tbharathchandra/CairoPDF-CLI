# PDF-CLI
CLI for creating PDF files

PDF-CLI is a command line tool for genrating PDF files. PDF-CLI can be used generate PDF files with shapes like Rectangle, Cube, Circle, Closed Polygons and Text.


### Usage of PDF-CLI
| Shape | Arguments |
| ------- | ----------- |
| Rectangle | `$(path)/fileName.pdf` `width` `height` `title` `rectangle` `x` `y` `w` `h` |
| Cube | `$(path)/fileName.pdf` `width` `height` `title` `cude` `x` `y` `a` |
| Circle | `$(path)/fileName.pdf` `width` `height` `title` `circle` `x` `y` `r` |
| Polygon | `$(path)/fileName.pdf` `width` `height` `title` `polygon` `x` `y` `$(anyPath)/pointsFile` |
| Text | `$(path)/fileName.pdf` `width` `height` `title` `polygon` `x` `y` `text` `size` |


* All the dimensions should be in points where (1 point == 1/72.0 inch)

### Format of points file
* First line should contain Bounding Box width and height separated by white-space.
* From second line each line should have one point with it's abscissa and ordinate separated by white-space.
* Points should be ordered in clockwise or anti-clockwise direction.
* Have a look at **`examples/star`** file.