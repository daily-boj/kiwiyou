use std::io::{stdin, BufRead};

fn main() {
    let (size, video): (usize, Vec<u8>) = {
        let stdin = stdin();
        let mut handle = stdin.lock();
        let mut size_line = String::new();
        handle.read_line(&mut size_line).unwrap();
        (
            size_line.trim().parse().unwrap(),
            handle
                .lines()
                .flatten()
                .flat_map(|line| line.trim().bytes().collect::<Vec<u8>>())
                .collect(),
        )
    };

    let mut arena = Vec::new();
    let root = construct_tree(&video, size, 0, 0, size, &mut arena);
    let mut output = String::new();
    traverse_tree(&arena, root, &mut output);
    println!("{}", output);
}

enum TreeNode {
    Value(u8),
    Subtree(usize, usize, usize, usize),
}

impl TreeNode {
    fn value_eq(&self, other: &Self) -> bool {
        match (self, other) {
            (Self::Value(a), Self::Value(b)) => a == b,
            _ => false,
        }
    }
}

fn construct_tree(
    video: &[u8],
    size: usize,
    offset_x: usize,
    offset_y: usize,
    actual_width: usize,
    arena: &mut Vec<TreeNode>,
) -> usize {
    if size == 1 {
        arena.push(TreeNode::Value(video[offset_y * actual_width + offset_x]));
    } else {
        let inner_size = size >> 1;
        let left_up = construct_tree(video, inner_size, offset_x, offset_y, actual_width, arena);
        let right_up = construct_tree(
            video,
            inner_size,
            offset_x + inner_size,
            offset_y,
            actual_width,
            arena,
        );
        let left_down = construct_tree(
            video,
            inner_size,
            offset_x,
            offset_y + inner_size,
            actual_width,
            arena,
        );
        let right_down = construct_tree(
            video,
            inner_size,
            offset_x + inner_size,
            offset_y + inner_size,
            actual_width,
            arena,
        );
        if arena[left_up].value_eq(&arena[right_up])
            && arena[right_up].value_eq(&arena[left_down])
            && arena[left_down].value_eq(&arena[right_down])
        {
            if let TreeNode::Value(value) = arena[left_up] {
                arena.push(TreeNode::Value(value));
            }
        } else {
            arena.push(TreeNode::Subtree(left_up, right_up, left_down, right_down));
        }
    }
    arena.len() - 1
}

fn traverse_tree(arena: &[TreeNode], node: usize, buffer: &mut String) {
    match arena[node] {
        TreeNode::Value(value) => {
            buffer.push(value as char);
        }
        TreeNode::Subtree(left_up, right_up, left_down, right_down) => {
            buffer.push('(');
            traverse_tree(arena, left_up, buffer);
            traverse_tree(arena, right_up, buffer);
            traverse_tree(arena, left_down, buffer);
            traverse_tree(arena, right_down, buffer);
            buffer.push(')');
        }
    }
}
