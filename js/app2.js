
class child{ 
	constructor() {
		window.addEventListener("resize", () => {
			console.log("arrow function");
			this.resize()
			console.log("ended");
		});
		window.addEventListener("resize", this.resize.bind(this));
	}
	resize() {
		console.log(this);
	}
}

class Test {
	constructor() {
		this.child = new child();
	}
	resize() {
	}
}

window.onload = () => {
	const test = new Test();
}