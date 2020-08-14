const cols = 1920
const rows = 1080
const bckg = 155
var colors = [255, 0]
const res=5
var gen = []
var next_gen = []
var grid;

function make2DArray(r, c) {
    let arr = new Array(rows);
    for (let i = 0; i < rows; i++) {
        arr[i] = new Array(cols);
    }
    return arr;
}

function update() {
    var next_grid = make2DArray(rows, cols);
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (i != 0 && j != 0 && i != rows - 1 && j != cols - 1) {
                let sum = grid[i - 1][j] + grid[i - 1][j - 1] + grid[i][j - 1] + grid[i][j + 1] + grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j - 1] + grid[i - 1][j + 1];
                if (sum == 3) {
                    next_grid[i][j] = 1;
                }
                else if (sum == 2) {
                    next_grid[i][j] = grid[i][j];
                }
                else {
                    next_grid[i][j] = 0;
                }
            }
        }
    }
    return next_grid;
}


function setup() {
    grid = make2DArray(rows, cols);
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            grid[i][j] = floor(random(2));
        }
    }
    createCanvas(cols, rows);
}
function draw() {
    background(255);
    for (let x = 0; x < rows; x = x + res) {
        for (let y = 0; y < cols; y = y + res) {
            fill(parseInt(colors[parseInt(grid[x / res][y / res])]));
            stroke(255);
            rect(x, y, res, res);
        }
    }
    grid = update();
}