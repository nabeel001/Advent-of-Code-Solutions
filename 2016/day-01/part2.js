const route = "L4, L1, R4, R1, R1, L3, R5, L5, L2, L3, R2, R1, L4, R5, R4, L2, R1, R3, L5, R1, L3, L2, R5, L4, L5, R1, R2, L1, R5, L3, R2, R2, L1, R5, R2, L1, L1, R2, L1, R1, L2, L2, R4, R3, R2, L3, L188, L3, R2, R54, R1, R1, L2, L4, L3, L2, R3, L1, L1, R3, R5, L1, R5, L1, L1, R2, R4, R4, L5, L4, L1, R2, R4, R5, L2, L3, R5, L5, R1, R5, L2, R4, L2, L1, R4, R3, R4, L4, R3, L4, R78, R2, L3, R188, R2, R3, L2, R2, R3, R1, R5, R1, L1, L1, R4, R2, R1, R5, L1, R4, L4, R2, R5, L2, L5, R4, L3, L2, R1, R1, L5, L4, R1, L5, L1, L5, L1, L4, L3, L5, R4, R5, R2, L5, R5, R5, R4, R2, L1, L2, R3, R5, R5, R5, L2, L1, R4, R3, R1, L4, L2, L3, R2, L3, L5, L2, L2, L1, L2, R5, L2, L2, L3, L1, R1, L4, R2, L4, R3, R5, R3, R4, R1, R5, L3, L5, L5, L3, L2, L1, R3, L4, R3, R2, L1, R3, R1, L2, R4, L3, L3, L3, L1, L2";
const instructions = route.split(', ');

let prev_direction = 'U';
const coords = new Set();
let x_coord = 0, y_coord = 0;
coords.add('0,0');

const getLoopCoord = () => {
    for (let instruction of instructions) {
        const distance = parseInt(instruction.slice(1));

        if (prev_direction === 'U') {
            if (instruction.startsWith('L')) {
                prev_direction = 'L';
                for (let i = 1; i <= distance; i++) {
                    x_coord--;
                    const new_coord = `${x_coord},${y_coord}`;
                    if (coords.has(new_coord)) return new_coord;
                    coords.add(`${x_coord},${y_coord}`);
                }
            }
            else {
                prev_direction = 'R';
                for (let i = 1; i <= distance; i++) {
                    x_coord++;
                    const new_coord = `${x_coord},${y_coord}`;
                    if (coords.has(new_coord)) return new_coord;
                    coords.add(`${x_coord},${y_coord}`);
                }
            }
        }
        else if (prev_direction === 'L') {
            if (instruction.startsWith('L')) {
                prev_direction = 'D';
                for (let i = 1; i <= distance; i++) {
                    y_coord--;
                    const new_coord = `${x_coord},${y_coord}`;
                    if (coords.has(new_coord)) return new_coord;
                    coords.add(`${x_coord},${y_coord}`);
                }
            }
            else {
                prev_direction = 'U';
                for (let i = 1; i <= distance; i++) {
                    y_coord++;
                    const new_coord = `${x_coord},${y_coord}`;
                    if (coords.has(new_coord)) return new_coord;
                    coords.add(`${x_coord},${y_coord}`);
                }
            }
        }
        else if (prev_direction === 'R') {
            if (instruction.startsWith('L')) {
                prev_direction = 'U';
                for (let i = 1; i <= distance; i++) {
                    y_coord++;
                    const new_coord = `${x_coord},${y_coord}`;
                    if (coords.has(new_coord)) return new_coord;
                    coords.add(`${x_coord},${y_coord}`);
                }
            }
            else {
                prev_direction = 'D';
                for (let i = 1; i <= distance; i++) {
                    y_coord--;
                    const new_coord = `${x_coord},${y_coord}`;
                    if (coords.has(new_coord)) return new_coord;
                    coords.add(`${x_coord},${y_coord}`);
                }
            }

        }
        else if (prev_direction === 'D') {
            if (instruction.startsWith('L')) {
                prev_direction = 'R';
                for (let i = 1; i <= distance; i++) {
                    x_coord++;
                    const new_coord = `${x_coord},${y_coord}`;
                    if (coords.has(new_coord)) return new_coord;
                    coords.add(`${x_coord},${y_coord}`);
                }
            }
            else {
                prev_direction = 'L';
                for (let i = 1; i <= distance; i++) {
                    x_coord--;
                    const new_coord = `${x_coord},${y_coord}`;
                    if (coords.has(new_coord)) return new_coord;
                    coords.add(`${x_coord},${y_coord}`);
                }
            }
        }
    }
}

const loop_coords = getLoopCoord().split(',');
console.log(Math.abs(loop_coords[0]) + Math.abs(loop_coords[1]));