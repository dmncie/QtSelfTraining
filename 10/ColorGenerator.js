var colors = [
            "white",
            "black",
            "cyan",
            "darkCyan",
            "red",
            "darkRead",
            "magenta",
            "darkMagenta",
            "green",
            "darkGreen",
            "yellow",
            "darkYellow",
            "blue",
            "darkBlue",
            "gray",
            "darkGrey",
            "lightGrey"
        ];


function getColor() {
    var color = colors[Math.floor(Math.random() * colors.length)];
    console.log("color generated:"+color)
    return color
}
