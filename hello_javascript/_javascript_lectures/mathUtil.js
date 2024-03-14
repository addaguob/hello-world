const PI = 3.14159;

function getCircumference(radius) {
    return 2 * PI * radius;
}

function getArea(radius) {
    return PI * radius * radius;
}

function getVolume(radius) {
    return 4 / 3 * PI * (Math.pow(radius, 3));
}

function getSurfaceVolume(radius) {
    return 4 * PI * radius * radius;
}