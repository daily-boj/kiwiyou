use std::io::{stdin, Read};

struct Context {
    memory: [u8; 32],
    alu: u8,
    pc: usize,
}

fn execute(ctx: &mut Context) {
    loop {
        let current = ctx.memory[ctx.pc];
        let instruction = current >> 5;
        let value = (current & 0b0001_1111) as usize;
        ctx.pc += 1;
        ctx.pc &= 0b0001_1111;
        match instruction {
            0b000 => ctx.memory[value] = ctx.alu,
            0b001 => ctx.alu = ctx.memory[value],
            0b010 => {
                if ctx.alu == 0 {
                    ctx.pc = value
                }
            }
            0b011 => {}
            0b100 => ctx.alu = ctx.alu.wrapping_sub(1),
            0b101 => ctx.alu = ctx.alu.wrapping_add(1),
            0b110 => ctx.pc = value,
            0b111 => break,
            _ => unsafe { std::hint::unreachable_unchecked() },
        }
    }
}

fn main() {
    let mut input = [0; 32 * 9];
    let stdin = stdin();
    let mut lock = stdin.lock();
    while let Ok(288) = lock.read(&mut input) {
        let mut memory = [0; 32];
        for i in 0..32 {
            let slice = &input[i * 9..];
            memory[i] = slice[..8]
                .iter()
                .map(|c| c - b'0')
                .fold(0, |a, n| a << 1 | n);
        }
        let mut ctx = Context {
            memory,
            alu: 0,
            pc: 0,
        };
        execute(&mut ctx);
        println!("{:08b}", ctx.alu);
    }
}
