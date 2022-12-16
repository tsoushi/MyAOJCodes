use std::io;

fn main() {
	let mut prime_num = 0;
	let mut input = String::new();
	io::stdin().read_line(&mut input);
	let length: u64 = input.trim().parse().unwrap();

	for _i in 0..length {
		let mut input = String::new();
		io::stdin().read_line(&mut input);
		let n: i64 = input.trim().parse().unwrap();
	
        if is_prime(n) { prime_num += 1; }
    }

	println!("{}", prime_num);
}

fn is_prime(n: i64) -> bool {
    if n == 2 { return true }
    else if n % 2 == 0 { return false }

    let mut i: i64 = 3;
    let lend = (n as f64).sqrt();
    while i as f64 <= lend {
        if n % i == 0 { return false }
        i += 2;
    }

    return true;
}
