use std::fs::File;
use std::io::{stdin, BufWriter, Write};
use std::os::unix::io::FromRawFd;

const INTRO: [&[u8]; 4] = [
    "\"재귀함수가 뭔가요?\"\n".as_bytes(),
    "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n".as_bytes(),
    "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n".as_bytes(),
    "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n"
        .as_bytes(),
];
const CONTENT: [&[u8]; 3] = [
    "\"재귀함수가 뭔가요?\"\n".as_bytes(),
    "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n".as_bytes(),
    "라고 답변하였지.\n".as_bytes(),
];
const OUTRO: &[u8] = "라고 답변하였지.\n".as_bytes();
const INDENT: &[u8; 200] = b"________________________________________________________________________________________________________________________________________________________________________________________________________";

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let number: usize = input.trim_end().parse().unwrap();
    let mut output = BufWriter::with_capacity(65536, unsafe { File::from_raw_fd(1) });
    output
        .write("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n".as_bytes())
        .unwrap();
    answer(&mut output, number - 1, 0);
}

fn answer(out: &mut impl Write, limit: usize, depth: usize) {
    let indent = &INDENT[..depth << 2];
    for message in &INTRO {
        out.write(indent).unwrap();
        out.write(message).unwrap();
    }
    if limit == depth {
        for message in &CONTENT {
            out.write(&INDENT[..(depth << 2) + 4]).unwrap();
            out.write(message).unwrap();
        }
    } else {
        answer(out, limit, depth + 1);
    }
    out.write(indent).unwrap();
    out.write(OUTRO).unwrap();
}
