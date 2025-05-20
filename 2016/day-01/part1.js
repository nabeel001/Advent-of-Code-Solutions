const route = "L4, L1, R4, R1, R1, L3, R5, L5, L2, L3, R2, R1, L4, R5, R4, L2, R1, R3, L5, R1, L3, L2, R5, L4, L5, R1, R2, L1, R5, L3, R2, R2, L1, R5, R2, L1, L1, R2, L1, R1, L2, L2, R4, R3, R2, L3, L188, L3, R2, R54, R1, R1, L2, L4, L3, L2, R3, L1, L1, R3, R5, L1, R5, L1, L1, R2, R4, R4, L5, L4, L1, R2, R4, R5, L2, L3, R5, L5, R1, R5, L2, R4, L2, L1, R4, R3, R4, L4, R3, L4, R78, R2, L3, R188, R2, R3, L2, R2, R3, R1, R5, R1, L1, L1, R4, R2, R1, R5, L1, R4, L4, R2, R5, L2, L5, R4, L3, L2, R1, R1, L5, L4, R1, L5, L1, L5, L1, L4, L3, L5, R4, R5, R2, L5, R5, R5, R4, R2, L1, L2, R3, R5, R5, R5, L2, L1, R4, R3, R1, L4, L2, L3, R2, L3, L5, L2, L2, L1, L2, R5, L2, L2, L3, L1, R1, L4, R2, L4, R3, R5, R3, R4, R1, R5, L3, L5, L5, L3, L2, L1, R3, L4, R3, R2, L1, R3, R1, L2, R4, L3, L3, L3, L1, L2";
const instructions = route.split(', ');

let x_distance = 0, y_distance = 0;
let prev_direction = 'U';

for (let instruction of instructions) {
    const distance = parseInt(instruction.slice(1));

    if (prev_direction === 'U') {
        if (instruction.startsWith('L')) {
            x_distance -= distance
            prev_direction = 'L';
        }
        else {
            x_distance += distance
            prev_direction = 'R';
        }
    }
    else if (prev_direction === 'L') {
        if (instruction.startsWith('L')) {
            y_distance -= distance
            prev_direction = 'D';
        }
        else {
            y_distance += distance
            prev_direction = 'U';
        }
    }
    else if (prev_direction === 'R') {
        if (instruction.startsWith('L')) {
            y_distance += distance
            prev_direction = 'U';
        }
        else {
            y_distance -= distance
            prev_direction = 'D';
        }

    }
    else if (prev_direction === 'D') {
        if (instruction.startsWith('L')) {
            x_distance += distance
            prev_direction = 'R';
        }
        else {
            x_distance -= distance
            prev_direction = 'L';
        }
    }
}

console.log(Math.abs(x_distance) + Math.abs(y_distance));