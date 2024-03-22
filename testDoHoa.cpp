#include <stdio.h>
#include <graphics.h>

// Function to draw a circle using Bresenham's algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (x <= y) {
        // Plot the points
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        // If the decision parameter is negative, choose E and update d
        if (d <= 0) {
            d = d + 4 * x + 6;
        }
        // If the decision parameter is positive, choose SE and update d
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    // Initialize the graphics mode
    initgraph(&gd, &gm, "");

    int xc = 200, yc = 200, r = 100; // Circle parameters
    drawCircle(xc, yc, r); // Call the function to draw the circle

    delay(5000); // Delay to show the result
    closegraph(); // Close the graphics mode
    return 0;
}


