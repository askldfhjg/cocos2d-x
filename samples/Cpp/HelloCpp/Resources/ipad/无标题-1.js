(function (lib, img, cjs) {

var p; // shortcut to reference prototypes

// library properties:
lib.properties = {
	width: 550,
	height: 400,
	fps: 24,
	color: "#FFFFFF",
	manifest: [
		{src:"images/_1fronthand.png", id:"_1fronthand"},
		{src:"images/_10hip.png", id:"_10hip"},
		{src:"images/_11chest.png", id:"_11chest"},
		{src:"images/_12backfoot.png", id:"_12backfoot"},
		{src:"images/_13backshin.png", id:"_13backshin"},
		{src:"images/_14backthigh.png", id:"_14backthigh"},
		{src:"images/_15backrobe.png", id:"_15backrobe"},
		{src:"images/_16backhand.png", id:"_16backhand"},
		{src:"images/_17backshoulder.png", id:"_17backshoulder"},
		{src:"images/_19cape.png", id:"_19cape"},
		{src:"images/_2frontshoulder.png", id:"_2frontshoulder"},
		{src:"images/_20backhair.png", id:"_20backhair"},
		{src:"images/_4headhair.png", id:"_4headhair"},
		{src:"images/_5headface.png", id:"_5headface"},
		{src:"images/_6robe.png", id:"_6robe"},
		{src:"images/_7idlefoot.png", id:"_7idlefoot"},
		{src:"images/_8frontshin.png", id:"_8frontshin"},
		{src:"images/_9frontthigh.png", id:"_9frontthigh"},
		{src:"images/位图72.png", id:"位图72"},
		{src:"images/位图73.png", id:"位图73"},
		{src:"images/位图74.png", id:"位图74"},
		{src:"images/位图75.png", id:"位图75"},
		{src:"images/位图76.png", id:"位图76"},
		{src:"images/位图77.png", id:"位图77"},
		{src:"images/位图78.png", id:"位图78"},
		{src:"images/位图79.png", id:"位图79"},
		{src:"images/位图80.png", id:"位图80"},
		{src:"images/shadow.png", id:"shadow"},
		{src:"images/weaponPic.png", id:"weaponPic"}
	]
};

// stage content:
(lib.无标题1 = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_twokeep_attack3();
	this.instance.setTransform(250.5,367.2,0.4,0.4);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(420.9,239.1,279.6,356);


// symbols:
(lib._1fronthand = function() {
	this.initialize(img._1fronthand);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,53,160);


(lib._10hip = function() {
	this.initialize(img._10hip);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,111,75);


(lib._11chest = function() {
	this.initialize(img._11chest);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,176,238);


(lib._12backfoot = function() {
	this.initialize(img._12backfoot);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,84,71);


(lib._13backshin = function() {
	this.initialize(img._13backshin);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,77,187);


(lib._14backthigh = function() {
	this.initialize(img._14backthigh);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,79,169);


(lib._15backrobe = function() {
	this.initialize(img._15backrobe);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,222,330);


(lib._16backhand = function() {
	this.initialize(img._16backhand);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,130);


(lib._17backshoulder = function() {
	this.initialize(img._17backshoulder);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,65,132);


(lib._19cape = function() {
	this.initialize(img._19cape);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,364,517);


(lib._2frontshoulder = function() {
	this.initialize(img._2frontshoulder);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,98,126);


(lib._20backhair = function() {
	this.initialize(img._20backhair);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,148,331);


(lib._4headhair = function() {
	this.initialize(img._4headhair);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,114,141);


(lib._5headface = function() {
	this.initialize(img._5headface);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,83,106);


(lib._6robe = function() {
	this.initialize(img._6robe);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,171,352);


(lib._7idlefoot = function() {
	this.initialize(img._7idlefoot);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,49,98);


(lib._8frontshin = function() {
	this.initialize(img._8frontshin);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,80,176);


(lib._9frontthigh = function() {
	this.initialize(img._9frontthigh);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,95,167);


(lib.位图72 = function() {
	this.initialize(img.位图72);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,111,51);


(lib.位图73 = function() {
	this.initialize(img.位图73);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,137,52);


(lib.位图74 = function() {
	this.initialize(img.位图74);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,110,50);


(lib.位图75 = function() {
	this.initialize(img.位图75);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,217,156);


(lib.位图76 = function() {
	this.initialize(img.位图76);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,216,156);


(lib.位图77 = function() {
	this.initialize(img.位图77);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,212,156);


(lib.位图78 = function() {
	this.initialize(img.位图78);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,197,147);


(lib.位图79 = function() {
	this.initialize(img.位图79);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,194,146);


(lib.位图80 = function() {
	this.initialize(img.位图80);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,192,146);


(lib.shadow = function() {
	this.initialize(img.shadow);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,80,23);


(lib.weaponPic = function() {
	this.initialize(img.weaponPic);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,206,779);


(lib.diying = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.shadow();
	this.instance.setTransform(0,0,5,4.999);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,400,115);


(lib._20backhair_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._20backhair, null, new cjs.Matrix2D(1,0,0,1,-74,-165.5)).s().p("ArjZ3IAAgKQGaAEGYgEIAAgKQkAmSiinyIgBAKQg3ERgsEfQAAgGgCgDQjmnfhEpQIAAlZQAEAUAGAQQAJjZAwi1QAniSAriSQACgEAAgFIAAgKQA6h6A4iEQB1kTCfj0QAMgTAHgdQEIAdDsg3IAbgIQACgBgBgFIGGAAIAAMLIgChaIgIlmQhjEdhNE5QjEMXgvO1QhhhPg1h6QgBAGgBAEQhoFmAtHPQFBAEE/gEIAAAKg");
	this.shape.setTransform(74,165.5);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,148,331);


(lib._19cape_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._19cape, null, new cjs.Matrix2D(1,0,0,1,-182,-258.5)).s().p("EgcbAoYIAAqxQBNkRBMkcQDOsMD+rlQD8rlEoq2QDFnPDZm4IADgFQADgCAAgFQDuggEDgGQBugCBvgFIAAgGICEAAIAJAPIgRABIAGAEQBuHRB3HHQDNMXDKMWIGSYtQBSE8BZEsIAAAdQAAgBAAAAQAAgBAAgBQAAAAAAAAQAAgBgBAAQrBhys4AoQnOAUmOBHQllBBkYB8QgBAYgCAZIgFApQgCAUAAATIAAApQAAAPgFANIgDAEQgCACAAAFIAKAAIgDAKg");
	this.shape.setTransform(182,258.5);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,364,517);


(lib._17backshoulder_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._17backshoulder, null, new cjs.Matrix2D(1,0,0,1,-36.1,-60)).s().p("AAEI/QgEgGgHgDQgCgCAAgEQhbjrg4kSQgRhWgQheQgFgFgDgGIgFgGQgCgCgFgBQgQiJAPh7IABgKIAAgJQAqhTBBg8IAFgDQAIgFAKAAIgYAAIAIgLIBfABIAIAEIgvACIAAAEQBZAjAvBNIAEAGQADADAFAAQANB0AaBoIABAJIAAAKQgVEWA7ETQAWBlAKBfQgPAJgEAVIgBAKIAAAJIgxAPIgCABQg2AEg3AAQgTgKgQgOgAhYpWIACgBIA/AAIARAIIhYABIAGgIg");
	this.shape.setTransform(36.1,60);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(14.2,0,43.8,120);


(lib._16backhand_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._16backhand, null, new cjs.Matrix2D(1,0,0,1,-39,-65)).s().p("AAUKJIgGgIICVgCQhCgHhDgWQAAgFgDgDQgUgPACgmIAGAAQgGhFAAhQIgEAAQABgWgPABIgBgJQgMg1ADhDQgEgBgCgCQj0lPh4maIAAhHIABAAQAigZA6gtIBDAAQAWARAfAPQAvAtAjA5QAZAoATAvQABAEADADQADADAFAAQAJA4ANA2QAQA+ASA6QACAEAAAFIAAAKQBBCsBPCkIADAFQADACgBAFQAhADAUANIAQAJQABAAABAGQBUAeAxBDIAEAFQADADAAAFIAAC+QAAAEACADQADADAFgBIAABaQglALgkAGIBJgBIAAAOgAkbqIIAAgBIApAAIAKAJIg/AAIAMgIg");
	this.shape.setTransform(39,65);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,78,130);


(lib._15backrobe_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._15backrobe, null, new cjs.Matrix2D(1,0,0,1,-111,-165)).s().p("Ak9ZyIgagIIGZAAQmegWl9iCQhIgxg5gMQgGAAAAABQgeBygsBgIAJAAIgFAKIggAAQgcgoghgyQgwhJgigsIAAijQDYqKEApcQErq7F9plQB0i3CDiqIAAgEIgQAAIACgGIGDAAIAKAJIg8ABIA/AAIAHAEIhAACIAAAEQB1AOBmAfIADABQATAEATABQAAAEACABIAQAIQACACAAAEQAVAFAUAEQAJACAJAEQABABABAEQAoAKAfAQIARAIQABABABAGIAwAOIAEADQADACAFABIgBPNIgChbIgHlqQAAEXgGEZQgTPIgQPUQlQBLk8ARIB2AAIgMABIgZAHgAMG5mIAcAAIAFABIgsABIALgCg");
	this.shape.setTransform(111,165);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,222,330);


(lib._14backthigh_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._14backthigh, null, new cjs.Matrix2D(1,0,0,1,-38.3,-84.5)).s().p("ADlNNIgXgIICYgCIgMAKgACeMqIgEgBQgIgFgKAAIhhhvIgFgGQgDgCgFAAQhNk8iOj1Qhri4gWkHQAvkICciaIAFgFQACgDAAgFQAKAAAIgDIAEgDQAIgDAKAAQAXgmAugRIADgBQAGgFAKAAIgzgBIABgGIANgEIB1ABIAMAFIgMABIACABQAIADAKAAQASAXALAcQABAFADACQACACAFABQBPE8BQFJQB1HchWHIQgsATgtAAQgxAAgygXgAl+s8IAAgCIAEACIgEAAgAAGtMIA/AAIASAHIhoABIAXgIg");
	this.shape.setTransform(38.3,84.5);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,76.6,169);


(lib._13backshin_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._13backshin, null, new cjs.Matrix2D(1,0,0,1,-47.5,-93.5)).s().p("ABBOnIABgIICggCIgYAFQgRAAgTAFgAD3NfQgCgDAAgFIAAgKQhTAihhgUIgDgCQgDgDgEABQgOglgYAUIgFACQgHAFgJAAQAZl5h9kXQhzj8g3lBQALkcBejLIADgFQACgCAAgFQAUgGATgJIADgBQAJgFAJAAIAKgEIgqgDIAVgOICRACIAHAFIgCAAIAAAEIAKABIAWAQIAMAIQBdEvgDGcQgGJsBvHVQgKgegRgWgAhoumIB3AAIAJAHIiKACIAKgJg");
	this.shape.setTransform(47.5,93.5);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(20,0,55,187);


(lib._12backfoot_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._12backfoot, null, new cjs.Matrix2D(1,0,0,1,-42,-35.5)).s().p("ADbFjIgGgIIgDgDIgEgDIAHgBIAZAAIgJgFQgIgGgIgGQgQgPgHgYQgngphSACQAAgFgCgCQhEguhNglQiagriTgvQAAgGgCgCQgQgUgLgHIAAgGQABgPgMgIIAAgOQAbhAARhMQAdiBBrg0IAAgEIgUAAQAGgHAEgJICVAAIAGAIIhMABIBNABIAFAFIgpABIACABQAJADAJAAQCUDECuCoIBEBAQA+A5BMArIAAB4QAAgFgCAAQgIgFgdAfIgDABIAqgBIAAgIIAAAcg");
	this.shape.setTransform(42,35.5);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,84,71);


(lib._11chest_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._11chest, null, new cjs.Matrix2D(1,0,0,1,-67.1,-118)).s().p("ADTScIgtgGIhCgIQhHgRg9gjIgQgJQgCgBAAgFQgtgFgcgUIgPgJQgCgBAAgFQhZgphOg0IgFgEQgDgDgFAAQgZgjgTgrIgDgEQgDgDAAgFQAjgyAhgzIAFgGQACgDAFAAQgHggAPgLQACgCAAgFIAAgKQgPg2gWg7QiFlgiMlPQg0h+gciEIAAhZQAEAGAGADIABgoQADhHAPg7IABgKIAAgKQALgJAQgHQAIgEAIgHIAFgFQACgDAAgFQBGgUBFgYIADgCQAIgEAKAAQAWgSAdgJIARgHQACgBAAgFQAKAAAKgCQAPgDANgIIAFgEQACgDAFAAQAAgFACgBIAugbIAEgDQAIgEAKAAQADgRAHgKQBQh7AUi0QAAgFADgCQACgDAFAAQAAgFABAAIA6gKQABAAAAgFIEqAAIAEAIIiNACICPACIAAAAIkIADIAAAFIAvAPIADABQAIAEAKAAQBZBMBKBcIAFAFQACACAAAFIAACCIAAAKIAAAKQAzBLBJAzIAOAIQACABAAAFQA0AXAuAfIAFAEQACACAFAAQBSBdAvCAQABAEAAAFIAAAKQBJB/gMDVIgBAKIAAAKQgjAmgcAwIgEAFQgDACAAAFQgtGggPHGIAAAKIAAAKQhNBihhBNQgGAFgIAEQgCABAAAFQg+ALg7AAIgQAAg");
	this.shape.setTransform(67.1,118);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,134.3,236.1);


(lib._10hip_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._10hip, null, new cjs.Matrix2D(1,0,0,1,-55.9,-37.3)).s().p("AjIFwICoABQhCAEhHAAIgfgFgAnJEUQgKgFgIgHIhBhBIgFgFQgCgDAAgFIgBgUQgGh1AOhbQADgPAAgPQAxhVAyhaQAcg0Ahg1IAAgCIACgDIAvgKQABAAAAgFIBcAAIAsAQIAEACIAAACIAIAAIA0AQQAUANAdAGIADABQAIAEAKAAQCeBqB7COIAEAFQADACAAAFQAagJAhgGIADgBQAIgEAKAAQBxhIBBh3IAEgGQADgDAFAAQAKAPAIAQIAEAHQADACAFAAQgBBCAKA2QABAFACADQADACAFAAIAAAKQggBKglBBQhdCsi8BNQAAAFgCABIgQAIIgEACQgIAEgKAAQiTAwiEAAQi2AAidhYg");
	this.shape.setTransform(55.9,37.3);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0.8,0,110.3,74.7);


(lib._9frontthigh_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._9frontthigh, null, new cjs.Matrix2D(1,0,0,1,-47.5,-83.5)).s().p("AnaNDIAAgLIDFACQgeADgWAGgAktM2QgDgDABgFQAAgEgCgFQgNgaguAAIgBgBQgJgDgKAAQibkRB/lJQCUmDCDmFQAXgWALglQAJghAOgeQACgEAAgFIAAgKQAGAAACgCIAEgDIAbgJIAEgDQADgDAEABQAsgoBCgOQAdgGAdgFQABgBAAgFIBTAAIAJAJQAuAsBDAoQAnAYAaA8IAtBmIAPAPIAACJQh3EAiAD+QimFQjDE4QgUAAgMAJQgSAMgPAOQgFAEgJAFQgBABAAAEQgLABgJgDQgLgCgKAAIgCABQgHADgLAAQAAAGgCABIgQAIIgEADIgCABIgDgBgAG6tCIAhAAIAAAfIghgfg");
	this.shape.setTransform(47.5,83.5);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,95,167);


(lib._8frontshin_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._8frontshin, null, new cjs.Matrix2D(1,0,0,1,-40,-88.1)).s().p("AmPNvIAAgPIBcACQgUgBgVgGQgggogTAoIAAgoQAwj8AgkVQAtmVBBmKQBuimCYh3QApgfAtgbIAjgMIAOgFIA+AAIAGAEIgQABIgBAFQArAHAkARIADACQAIAEAKAAQAuAiAEBMQAAAFADACQADADAFAAIAABfIgJAHIgBg+IAAAKIAAAyIgFAIQgTATgEAWIiTEIQkZIBiiJ4QgiARgkAAIBXACIgmALgADQtuIAHACIAaABIACABIgtABIAKgFg");
	this.shape.setTransform(40,88.1);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0.2,80,175.9);


(lib._7idlefoot_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._7idlefoot, null, new cjs.Matrix2D(1,0,0,1,-24.5,-49)).s().p("Aj0HqIAAmAQAEBnAGBlQAGhpAYhOQAehdALhmQAFgGADgGIAEgGQADgDAEAAQARhcAUhgQAYh0A7hWIAAgEQhuAAhuAEIClABQhSAChSAHQAAABgBAHIAAgSIAAgKIHoAAIAAC1IAAgNIgCBTQgDCxAFCnIAAGAg");
	this.shape.setTransform(24.5,49);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,49,98);


(lib._6robe_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._6robe, null, new cjs.Matrix2D(1,0,0,1,-85.5,-176)).s().p("AkrbfQgJgGgKgDIAsAAQhpgOhVglQgJgJgMgFQglgNgLggQAPq8AYqpQActNAhtAQAAgGgCAAQjdhXjGg6IAAi+IC/AAIApAQIgBAAIAAAEQF4CNHEgtIAAAEIAAAKQBFGHBeFxQDJMXDAMmIBeGIIAAAbQgGAEgEAGIAAgIQhsCKiiBTIgUAUQicAnhUA8QhNBZheBIQg0AQgmAhQhbAkhqAYgAlubXIAEAAIgCAAIgCAAg");
	this.shape.setTransform(85.5,176);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,171,352);


(lib._5headface_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._5headface, null, new cjs.Matrix2D(1,0,0,1,-41.9,-53)).s().p("AArISQgHgGgIgEIAWAAIgKgKQiohBhgiHQgRgXgbgHQAAgFgBgBIgmgJQgBgBAAgEQgfgTgZgZQgXgWgKgjQgBgEgCgDQgDgCgFAAIgBhlQgBhBAegjIAEgDQANgEAPgBQgvj3CBh5QAcgbAegYQAKAAAJgEIAhgNIAQgHQACgBAAgGQAUgEAVgDQAdgDAdgEQABgBAAgFIHAAAIAAAGQigAAigAEIC+ABIiCAFIAAAEQAPAGAQACQAJACAIAFQACABAAAEIAxAPIADABQAIAFAKAAQAbAgAjAZIAGAFQACACAAAFQAyBMAKBzQAAAFADACQACADAFAAIAACKIgFAGIgFhVIAAAKIAAApQghA4gRBAQhHEeifDAIgoAUg");
	this.shape.setTransform(41.9,53);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0.9,0,82.1,106);


(lib._4headhair_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._4headhair, null, new cjs.Matrix2D(1,0,0,1,-57,-51)).s().p("AlJHBIAAgKIAAgKQgDgQgOASQgDADAAAFIAAAKQgdg3gOhSQgIgugJhCQAAgBgIAEQgCABAAAFQgRgbAHg1IAAgKIAAgKQgjAPgcAVQgHAEgIgEQgCgBAAgFQASgbgDg1IABgKQAHgyAZgeIAFgFQACgDAFAAQg3gFg2gKQAAAAAAAAQAAAAAAAAQAAgBABAAQAAgBABAAQACgDAFAAIBRhjQAegjAgghIAFgFQACgDAAgFQAdgBAQgOQAFgFAIgEQACgBAAgFQgBgKgfgbIgFgFQgDgDAAgFQAwgRAogaIAEgDQAIgEAKAAQANgWAlgDIAAgFIAAgKQgPgKgMgMIgFgFIgCgCQDLAnBXhJQAAAAABgBQAAAAAAgBQAAAAAAgBQgBgBAAAAQgCgCgEgBQADgMAJAAIAGACIAAAAIBEAiIAEACQAIAEAKAAQAKAFAIAIIADADQATAEAUAAQAKAKAMAIIAGAFQACACAAAFQAeAFgJgjIgBgKIAAgKQgOgNA1ASIADABQAIAEAKAAIAyApIALAJQAeAZAIAtIABAKIAAAKQAZAFAYAKIADABQAIAEAKAAQAfAeANAxIAEAMIAfBQQABAEAAAFIAAAKQgSgVgpAGQgBAAAAAFIAAAKQgHAbAPAHQACABAAAFIAABsIAAAKIAAAKQAAAFgCABQgIAEgCAEQgTAoABA4IAAAKIAAAKQg0gIgDg9IgCgDQgDgDAAgFQgVAJgMATIgEAFQgDACAAAFQgFAAgCgCQgDgDgBgEQgPgnAGg+IAAgKIAAgKQgZAKgNAWQgCADgCABQgIAEgKAAIAAhGIAAgJIAAgJQgUgkgaAfQgEAFgIAEQgCABAAAEQgoAJggAQIgQAIQgCABAAAFQhBgUhLgFIgCABQgHAEgJAAQgRASgWAOQgGADgDAGQgWAigSAkIgEAHQgDACgFAAIgJBQQgBAKgDAJQgNAoAGA9IAAAKIAAAKQAIAcgcgDIgCADQgDACgFAAQgSg5gHBDIgCADQgDACAAAFQgMAIgUglIgEgMQgMgtgWgdIgCADQgDACgFAAQgMgNgDgaIgBgDQgTgmgNgoQgCgFgCgCQgDgDgFAAQAAAUgLAIIgGAFQgDACAAAFIAAAKQgDA2AMAlQABAEAAAFIAAAKQAKAKAIAMQACADABAFQAHAwAeAZQACACAAAFIAAAKQgHAmgfAQIgEAEQgDACgFAAIAAg8gAgDn8IAHAAIgGAEIgBgEg");
	this.shape.setTransform(57,51);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(1.1,0.1,112,102);


(lib._3weapon = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img.weaponPic, null, new cjs.Matrix2D(0.705,0,0,0.705,-74.4,-271.2)).s().p("EgBzApvIgDAAQgCgoAFgmQAhgeACgaQAAgEgBgDQgLgTAMgYIAAgHQgFgMgCgXQANgMACgXIgBgHIgHg5QABgDABgDQAKgTgMgYQAQgbgeAGIAAgIQABgRAGgSQAAgDgCgCQgLgJANgOQgWgUAlgBQgBgEgBgBQgQgNgKgRIAAgHIAGgkQAAgDgCgCQgLgJANgOQAXAAgBgcQgCgYgNgLIABgIQACgbgKgPQAEgWAKgNIABgHIAHgcQgBAAgBAAQgBAAAAAAQgBAAAAgBQAAAAgBAAQgEgSAJgKQgBAAgBAAQgBAAAAAAQgBAAAAAAQAAgBgBAAQgHgSAMgCQgBgDgBgCQgMgJAOgOIgEAAQADgZgHgDQgCgWgMgOIAAgHQADgXgJgMQAAAAABAAQABAAAAAAQABAAAAAAQAAAAAAgBQAFgSgIgJQAWgCAGgTQgbgCgBgaIAAgHQAHgZgHggQAaAQACgeQgggwAYglIAAgHQAAgKAIgSIgBgHQgEgPgDgbQhDgchDAGIgNgOIhAAAIgOgOQhugLh0gRIgOgOQglAOgwgcQANgTAIgYQAUgBACgUQBxgEBxgKIAAgHQAEgsAQghIAAgHIgHgPIAEAAQgBgWAMgGIgBgHIgHgOIAEAAQgBgPAMABQAAgEgCgCQgKgZASgoIgBgGIgFgPIADAAQgCglAMgTIAAgHQgBgQgGgUIAEAAQgCgdANgNQgBgDgBgCQgMgJAOgOQgBAAgBAAQgBAAAAAAQgBgBAAAAQAAAAgBgBQgHgRAMgCIAAgHQgDgagFgfQABAAABAAQABAAAAAAQABAAAAAAQAAAAAAgBQAJgugNgeQABAAABAAQABAAAAAAQABgBAAAAQAAAAABAAQAEgSgJgKQABAAABAAQABAAAAAAQABAAAAAAQAAAAABgBQADgJAAgLIAAgHQAAgOgIgHQABAAABAAQABAAAAAAQABgBAAAAQABAAAAAAQAIgSgNgCQAAgEACgBQAMgJgOgOIABgHQAGgMABgYIgBgHIgOhNIABgHQACgQAEgUIgBgGQgIgMgEgRQAAAAABAAQABAAAAAAQABAAAAAAQAAAAAAgBQAFgSgIgJIgBgHQgCgaADgfQAAgDgCgCQgQgUALgYIgBgHQgRgnAKggQAAgDgBgCQgTgWANgWQAAgEgCgCQgSgTANgWIgBgHQgOg0gNg2QAAgEABgDQAUgmgHghIAEAAQgBgPALABIAAgHQACgagCgfIAEAAQgBgPALABIABgHQANhYABhKIADAAQgBgPALABIAAgHQABgLgIgYIAEAAQgBgQAMABIAAgHIgIgcQABAAABAAQABAAAAAAQABAAAAAAQAAAAABgBQADgNAHgHQgBAAgBAAQAAAAgBAAQAAAAgBAAQAAgBgBAAQgHgSAMgCIAAgHIAAhqIADgBQAFgSgIgJIADAAQgBgpAMgXIgBgGQgIghAJgmIgBgHQgCgagEgfIABgHQAEgMACgXQAAgEgCgCQgJgTALggIgDAAQAAgkgLgUQABAAABAAQAAAAABAAQAAAAABgBQAAAAAAAAQAIgSgMgCIAAgHQACgQAFgUQAAgDgCgDQgHgMgFgRQAAgDABgCQAMgJgNgOIAAgHQgCgaACgfQgBgDgBgCQgQgUAKgYQABgDgCgDQgSgVAMgWQAAgEgBgCQgTgWAOgWQAAgDgCgDQgWgmAJghQAAgEgBgDQgagvAHgtQAAgEgCgDQgPglgMgpIABgGQALgcARgWIAAgHIAAgVQAAAAABAAQABAAAAgBQABAAAAAAQABgBAAAAQATgegDgSQABgDABgDQAQgdASgcQgBgEACgDQAIgegCgGIABgGIAbgrIAAgHQgCgeAQgMIAEAAQgFgfAegaIAAgHIAAgVIADAAQgBgPALABIAAgHQABgYAOgLIADAAQgEgiAdgeIAAgHQgEgZASgDIAAgHIAAgVQABAAABAAQAAAAABAAQAAAAABgBQAAAAAAAAQAOgtAYggQAAgEABgDQAJgdgCgGQAAgBAAgBQAAAAAAgBQAAgBAAAAQAAAAAAgBQASgIgFgeQABAAABAAQABAAAAAAQABAAAAAAQAAAAABgBQAKghAUgWIAAgHQABgkAVgOIAAgHIAAgVQABAAABAAQAAAAABAAQAAAAAAAAQAAAAAAgBQAIgTAKgPQAXAKgEAnIAEABQACASAQADIABAGQASA6AQA+QAmAvALBJIAEABQACASAPADIABAHQADAqAZAVQgFAoAZAKIABAGIAjB5QABAAABAAQAAAAABAAQAAAAABABQAAAAAAAAQAVAaADArIArBHIABAGIAiB5QAAAAABAAQABAAAAAAQABAAAAABQABAAAAAAIAmBTIAAAHQADAigRAJIAAAHQAEAogTAJQAAAEACABQAKALgTAMQAAABABABQAAABAAAAQAAAAAAABQAAAAABAAQAKACgFAPIgDAAQACAegTAGIAAAHQgBAaABAeIgEAAQABAPgMgBIABAEQALACgFAQIgDAAQgPBPAFAoIgEABQgGAzgMAoIABAHIAGAjIgDAAQABAPgMAAIABAHQADAYADAgIgBAGQgKATALAYQgBAAgBAAQAAABgBAAQAAAAAAAAQAAABAAAAQgEAJAAALIAAAHQAAANAHAIIgDAAQgJBWAMBFIgDABQgFASAIAJQgBAAgBAAQAAABgBAAQAAAAgBAAQAAABAAAAQgIARAMACIgBAIIgGAjIABAGQAOAngIAgIABAHIAOAyQAAABgBAAQAAABAAAAQAAABAAAAQAAAAAAAAQgLADAEAPQABAAABAAQABAAAAAAQABAAAAAAQAAABAAAAQAJAugFAYIABAGIAMAdIgBAHIgFAOIADAAQgCAXAMAFIgBAHIgGAOQABAAABAAQABAAAAABQABAAAAAAQAAAAABAAQAMAhgKAQQABADABADQALAYAIAaIgBAHIgFAOQAAAAABAAQABAAAAABQABAAAAAAQAAAAAAAAQAPBTAYBIIgBAGQgKAgAEAnIgEAAQABAPgLgBIAAAEQAMACgFAPQgBAAgBAAQAAABgBAAQAAAAgBAAQAAAAAAAAQgLAuAIAWIgDAAQAAAPgMgBIABAHQAFAtgTA2QgBADACADQAKAZgTAnIABAHIAHAPIgEAAQACAlgNATIABAHQABAQAFATIgDAAQABAPgLAAIAAAHIAGAjQAAADgCACQgLAJANAOIgDAAQAAAcgKAOIADAAQgGAiAKAXIgCAHQgIAiAKAkQAAAEgCADQgKASAMAZIgCAHIgFAjIAAAHIANBOIgDAAQADAYgGASQAAAEABABQAMAJgNAOIADAAQgCAlAMAUIgBAGIgGAPQABAAABAAQABAAAAAAQABAAAAAAQAAABAAAAQAMBHgBAwQgBADACADQAUAlgIAiQAAAEACADQALAYAJAaQAAADgBADQgHALAIASQBgAWB6gPQAPAMAOgMQAAAEABACQAXAbALAmIhqAcQgNgBgIgGIg4AVIgWgHIhjAcIgcgHQgvAQg0AMQgMAAgJgHQgaAJgXANQgRgKgLAKQAAADACACQAQATADAgIgEAAQAEAYgHALQgSALgDAZIADAAQgEAJABATIAAAHQAAAOAHAHQAAABAAABQAAABAAAAQgBABAAAAQAAABgBAAQgLAJANAOQgBAAgBAAQAAABgBAAQAAAAgBAAQAAAAAAABQgIARAMACIgBAHQgFANgBAJQAAABAAAAQAAABAAABQABAAAAAAQAAABABAAQAKAFACAMIAEAAQACAYgGASIAAAEQAMACgFAPQgBAAgBAAQAAABgBAAQAAAAgBABQAAAAgBAAQgYAjAWgJIAAAHQAIAcAGAdQgGAagWAJQAjAGgOAeIADAAQAEAegHAMQgGATgPAJIAAAHQABAQAGATQAAAEgCABQgLAKANAOQgBAAgBAAQAAAAgBAAQAAAAgBABQAAAAAAAAQgIASAMACIgBAGQgFANgBAXQAAAEACACQAIATgKAgQADAAACABQAVAVgMAUQAAABAAAAQAAABAAABQABAAAAABQAAAAAAAAQALAFgFATIAAAHQgDAcgLgOIgEAAQACAbAXAJQAAABAAAAQAAABAAABQgBAAAAABQAAAAAAAAQgQANARALQAAADgBACQgKAKALAUQgiAcAbgHIAAAHIAHArIAAAHIgHAjQgZgCAEAeIADAAQACAegFAbQANAZAWARIABAHQASAtgMAoQhBAMg/AAQg9AAg/gMg");
	this.shape.setTransform(2.3,-159.1);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-60.9,-427.5,126.3,559.7);


(lib._2frontshoulder_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._2frontshoulder, null, new cjs.Matrix2D(1,0,0,1,-49,-63)).s().p("AnpJ2IAAgKICiABQg1gFg5gVIgEgBQgHgEgLAAQgJgegJgfQgBgEgDgDQgDgDgFABIAAgpQCZkaCKkhQCAkMC0jQQAJgFALgDQAJgDAJgEIAEgDIAFgFQADgDgBgFQAVgEAUgCQAigEAjgEIAAgGIC/ABQgtABgtAEIgDACQgCADgGgBQAKAKAIAMIAFAGQADADAFAAQA4CUAcC0IADAEQACACABAFQgGAjgSAXIgEAFQgDADAAAEQhNA6hEBDQgFAFgHAEQgCABAAAGQgOALgaADIgDADQgDACgFABQgKAEgHAGIgFAFQgDADgEgBQiWE2jOD9QgDADABAEIAAALQg2Aag6AFQF2ACF4gDIAAAKgAnpp1IPTAAIAAAGQmjgBmhAFICPABIkeAFg");
	this.shape.setTransform(49,63);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0,98,126);


(lib._1fronthand_1 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.bf(img._1fronthand, null, new cjs.Matrix2D(1,0,0,1,-26.5,-79.8)).s().p("ACHMYIAKAAQhsgihvgaIgTgUIgzgKQgFAAgCgDQgigfgIg4IAAgKQAeoxhlmrIAAiJQAEAKAGAGIgBgnQgCg8AMgpQACgEgBgFIAAgLQAGAAAAgBQAWhCA9gbIADgCQATgIARgHIAWgDIABgDIAIgDIA1AAIAMAFIgDABIAAAEQALABAMABIARAGIAAAAQADACAEAAQAKAGAIAHIAFAFQACADAGAAQBPC/gqEOQgqEDAZEMQBMAyBDA9IAEAFIAhArIAKANIAABCQgMAIgNAMQgsAqAAApIABAPQgOAeAAATIABAFIgBAGQAAAGAHARQAFASAAALIgCAJIgCAJQgBADAEAHQADAHAAAEIgzAtIgLgCgAgysZIAJADIgfABIAWgEg");
	this.shape.setTransform(26.5,79.8);

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(0,0.4,53,159);


(lib.AvatarSkel_gracex6vbdxjrjx = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图76();
	this.instance.setTransform(-495.7,-358,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-495.7,-358,991.5,716.1);


(lib.AvatarSkel_gracew8cb19o34u = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#FFFFFF").s().p("Eg7yBakQWymPR7x7UAbegbgAAAgm6UAAAgm5gbegbgQx7x72ymPQMKjVNjAAUAm5AAAAbgAbfUAbfAbgAAAAm5UAAAAm6gbfAbgUgbgAbfgm5AAAQtjAAsKjVg");

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-382.7,-600.9,765.5,1202);


(lib.AvatarSkel_graceuhon7p8h6s = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#00CCFF").s().p("Egv7Bd4IF7gRQDAgPC8gZQGGg2FxhlQWymPR5x7UAbggbgAAAgm6UAAAgm5gbggbgQx5x72ymPQlxhlmGg1Qi8gajAgOIl7gSIB/gBUAm7AAAAbdAbfUAbgAbgAAAAm5UAAAAm6gbgAbgUgbdAbfgm7AAAg");

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-306.8,-600.9,613.7,1202);


(lib.AvatarSkel_gracet01wjjbdvx = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图73();
	this.instance.setTransform(-314.4,-119.3,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-314.4,-119.3,628.8,238.7);


(lib.AvatarSkel_gracern8hroqfoa = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图72();
	this.instance.setTransform(-254.7,-117,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-254.7,-117,509.5,234.1);


(lib.AvatarSkel_graceq4p6xhg6z1 = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图80();
	this.instance.setTransform(-440.6,-335.1,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-440.6,-335.1,881.3,670.2);


(lib.AvatarSkel_graceozrojj3zk2 = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图78();
	this.instance.setTransform(-452.1,-337.3,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-452.1,-337.3,904.2,674.7);


(lib.AvatarSkel_gracekwjkqolyvt = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#FFFFFF").s().p("ApxBqQFtk1IcAcICjATIAjAnQBqB0AhCLIAJAoQrKmuoZFmg");

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-62.6,-17.9,125.3,35.8);


(lib.AvatarSkel_gracehwf027i44k = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#FFFFFF").s().p("Egy5BdnQDAgPC8gZQGFg2FyhlQWymPR5x7UAbfgbgAAAgm6UAAAgm5gbfgbgQx5x72ymPQlyhlmFg1Qi8gajAgOIH7gTUAm7AAAAbdAbfUAbgAbgAAAAm5UAAAAm6gbgAbgUgbdAbfgm7AAAg");

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-325.8,-600.9,651.7,1202);


(lib.AvatarSkel_gracehdv8locvdi = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图74();
	this.instance.setTransform(-252.4,-114.7,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-252.4,-114.7,504.9,229.5);


(lib.AvatarSkel_gracefo29w0fz14 = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#FFFFFF").s().p("Eg12Bc/QGFg2FxhlQWzmPR7x7UAbdgbgAAAgm6UAAAgm5gbdgbgQx7x72zmPQlxhlmFg1QGug7HHAAUAm8AAAAbdAbfUAbfAbgAAAAm5UAAAAm6gbfAbgUgbdAbfgm8AAAQnHAAmug6g");

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-344.8,-600.9,689.6,1202);


(lib.AvatarSkel_gracefdlhib7iik = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#FFFFFF").s().p("Egw6Bd1ID9gOQDAgPC7gZQGGg2FxhlQWymPR5x7UAbggbgAAAgm6UAAAgm5gbggbgQx5x72ymPQlxhlmGg1Qi7gajAgOIj9gOQB9gFCAAAUAm7AAAAbeAbfUAbfAbgAAAAm5UAAAAm6gbfAbgUgbeAbfgm7AAAQiAAAh9gEg");

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-313.1,-600.9,626.3,1202);


(lib.AvatarSkel_graceb4ete505xt = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#FFFFFF").s().p("AlvAxQhDAZg/AfQFglmHxBhIAcAnQBVBzAZCMIAIAoQmOknnTCmg");

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-49.8,-17.8,99.7,35.7);


(lib.AvatarSkel_grace17ekykc8dh = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图79();
	this.instance.setTransform(-445.2,-335.1,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-445.2,-335.1,890.5,670.2);


(lib.AvatarSkel_grace8ylhnzm2g3 = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图77();
	this.instance.setTransform(-486.5,-358,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-486.5,-358,973.1,716.1);


(lib.AvatarSkel_grace7i2tln3wpn = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图75();
	this.instance.setTransform(-498,-358,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-498,-358,996,716.1);


(lib.AvatarSkel_grace6lih4qonok = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图75();
	this.instance.setTransform(-498,-358,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-498,-358,996,716.1);


(lib.AvatarSkel_grace5kj46nki8v = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图75();
	this.instance.setTransform(-498,-358,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-498,-358,996,716.1);


(lib.AvatarSkel_grace4uilax7kgw = function() {
	this.initialize();

	// 图层 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#FFFFFF").s().p("AAtgrQkYhlkABeQF8isGkBAIAkAnQBnBuAjCRIAJAoQjRiIjuhTg");

	this.addChild(this.shape);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-49.3,-17.7,98.6,35.3);


(lib.AvatarSkel_grace3sxh271ljr = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.位图75();
	this.instance.setTransform(-498,-358,4.59,4.59);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-498,-358,996,716.1);


(lib.shape318 = function() {
	this.initialize();

	// Layer 2
	this.instance = new lib.AvatarSkel_grace4uilax7kgw();
	this.instance.setTransform(-28.4,-133.4);

	// Layer 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#00CCFF").s().p("AHfDFQjPiGjshSQkOhij5BaIgSAAQgKgEgEgKQgEgJAEgJQAEgKAJgEQGEivGrBCQAJABAGAGIAkAnQBrBzAkCXIAKApQABAHgCAHIgJAMQgHAEgHAAQgIAAgGgEg");
	this.shape.setTransform(-28.5,-133.5);

	this.shape_1 = new cjs.Shape();
	this.shape_1.graphics.f("rgba(0,204,255,0.498)").s().p("AHRDaQjNiFjohTIAAAAQkGhdjwBYIgmgBQgSgJgIgSQgHgTAHgTQAIgSASgJQGKiyGzBDQARACAMANIAkAnIAAAAQBwB4AmCdIAJApQAEAPgGAOQgFAOgNAJQgNAJgPAAIgCAAQgOAAgMgIgAAkgTQDsBSDPCGQAGAEAIAAQAHAAAHgEIAJgMQACgHgBgHIgKgpQgkiXhrhzIgkgnQgGgGgJgBQmrhCmECvQgJAEgEAKQgEAJAEAJQAEAKAKAEIASAAQB4grB8AAQCIAACLAzg");
	this.shape_1.setTransform(-28.5,-133.5);

	this.addChild(this.shape_1,this.shape,this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-82.8,-156.1,108.7,45.4);


(lib.shape317 = function() {
	this.initialize();

	// Layer 2
	this.instance = new lib.AvatarSkel_gracekwjkqolyvt();
	this.instance.setTransform(-54.6,-133.6);

	// Layer 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#00CCFF").s().p("AJlDIQq7mloNFcQgJAFgJgBQgKgCgGgIQgGgIABgKQABgKAIgGQF0k8InAdIABAAICjAUQAJABAGAHIAkAnQBuB5AiCRIAJAnQADAKgGAJQgFAJgKADIgGAAQgHAAgGgDg");
	this.shape.setTransform(-54.6,-133.7);

	this.shape_1 = new cjs.Shape();
	this.shape_1.graphics.f("rgba(0,204,255,0.498)").s().p("AJYDdQqsmboBFRQgRALgTgDQgUgDgMgQQgMgQACgUQACgTAPgNQF8lCIxAdIACABIClATQASACAMAOIAjAnQBzB+AjCXIAJAnQAFAUgKASQgLASgUAFQgHABgGAAQgNAAgMgHgAJlDIQAJAFAKgCQAKgDAFgJQAGgJgDgKIgJgnQgiiRhuh5IgkgnQgGgHgJgBIijgUIgBAAQongdl0E8QgIAGgBAKQgBAKAGAIQAGAIAKACQAJABAJgFQDuidERAAQFJAAGADmg");
	this.shape_1.setTransform(-54.6,-133.7);

	this.addChild(this.shape_1,this.shape,this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-122.3,-156.5,135.3,45.8);


(lib.shape316 = function() {
	this.initialize();

	// Layer 2
	this.instance = new lib.AvatarSkel_graceb4ete505xt();
	this.instance.setTransform(-67.4,-133.6);

	// Layer 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#00CCFF").s().p("AHjDGQmDkfnGChIAAAAQhCAZg9AfIgRACQgJgDgGgHQgFgHAAgJQABgKAHgGQFplwH+BjQAKACAGAIIAcAnQBYB4AaCSIAAAAIAHAnQACAHgDAIQgDAHgHAEQgHAEgHAAQgIgBgGgEg");
	this.shape.setTransform(-67.5,-133.6);

	this.shape_1 = new cjs.Shape();
	this.shape_1.graphics.f("rgba(0,204,255,0.498)").s().p("AHwDkQgQgBgMgJQl5kXm5CdIABAAQhBAYg8AeQgRAIgRgEQgSgEgLgPQgLgPABgSQACgSANgOQFyl5IMBmQATADAMARIAcAnIAAgBQBbB9AcCXIAHAnQADAPgGAOQgGAPgNAIQgNAIgOAAIgCAAgAHjDGQAGAEAIABQAHAAAHgEQAHgEADgHQADgIgCgHIgHgnIAAAAQgaiShYh4IgcgnQgGgIgKgCQn+hjlpFwQgHAGgBAKQAAAJAFAHQAGAHAJADIARgCQA9gfBCgZIAAAAQClg7CbAAQESAAD3C5g");
	this.shape_1.setTransform(-67.5,-133.6);

	this.addChild(this.shape_1,this.shape,this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-122.3,-156.4,109.7,45.6);


(lib.shape290 = function() {
	this.initialize();

	// Layer 1
	this.instance = new lib.AvatarSkel_graceuhon7p8h6s();
	this.instance.setTransform(1120.1,42.2);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(813.3,-558.8,613.7,1201.9);


(lib.shape289 = function() {
	this.initialize();

	// Layer 1
	this.instance = new lib.AvatarSkel_gracefdlhib7iik();
	this.instance.setTransform(1113.8,42.2);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(800.6,-558.8,626.4,1201.9);


(lib.shape288 = function() {
	this.initialize();

	// Layer 1
	this.instance = new lib.AvatarSkel_gracehwf027i44k();
	this.instance.setTransform(1101.1,42.2);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(775.3,-558.8,651.7,1201.9);


(lib.shape287 = function() {
	this.initialize();

	// Layer 2
	this.instance = new lib.AvatarSkel_gracefo29w0fz14();
	this.instance.setTransform(1082.2,42.2);

	// Layer 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#00CCFF").s().p("Eg2YBg2QhdgNg+hGQg9hHgBhdQABheA9hHQA+hGBdgNQF1gzFihhQVzl/RLxLUAaUgaWAAAglTUAAAglSgaUgaWQxLxL1zl/Qlihhl1gzQhdgNg+hGQg9hHgBhdQABheA9hHQA+hGBdgNQG/g9HYAAUAohAAAAcpAcpUAcoAcoAABAohUgABAoigcoAcpUgcpAcogohAAAQnYAAm/g9g");
	this.shape.setTransform(1082.2,42.2);

	this.addChild(this.shape,this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(712.4,-583.8,739.6,1251.9);


(lib.shape286 = function() {
	this.initialize();

	// Layer 2
	this.instance = new lib.AvatarSkel_gracew8cb19o34u();
	this.instance.setTransform(1044.2,42.2);

	// Layer 1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#00CCFF").s().p("Eg8TBcdQgpgMgZghQgagiAAgqQAAgqAagiQAZghApgLQWSmIRkxjUAa4ga7AABgmGUgABgmFga4ga7Qxkxj2SmHQgpgMgZghQgagiAAgqQAAgqAagiQAZghApgLQMajaN0AAUAntAAAAcEAcEUAcEAcEAAAAntUAAAAnugcEAcEUgcEAcEgntAAAQt0AAsajZg");
	this.shape.setTransform(1044.2,42.2);

	this.addChild(this.shape,this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(649,-571.3,790.5,1226.9);


(lib.元件1 = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_grace8ylhnzm2g3();
	this.instance.setTransform(486.4,358);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-0.1,0,973.1,716.1);


(lib.AvatarSkel_gracez13aevqqpz = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_graceq4p6xhg6z1();
	this.instance.setTransform(0,-0.1);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-440.6,-335.2,881.3,670.2);


(lib.AvatarSkel_gracez2avpshr9j = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_grace5kj46nki8v();
	this.instance.setTransform(0,-0.1);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-498,-358.1,996,716.1);


(lib.AvatarSkel_gracey7qgfcvsnv = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_gracehdv8locvdi();

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-252.4,-114.7,504.9,229.5);


(lib.AvatarSkel_gracexjqeglzfjo = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_grace7i2tln3wpn();
	this.instance.setTransform(0,-0.1);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-498,-358.1,996,716.1);


(lib.AvatarSkel_gracex8iavwo1pu = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_grace3sxh271ljr();
	this.instance.setTransform(0,-0.1);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-498,-358.1,996,716.1);


(lib.AvatarSkel_graces1ui2jwpjl = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_grace6lih4qonok();
	this.instance.setTransform(0,-0.1);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-498,-358.1,996,716.1);


(lib.AvatarSkel_gracer86kyi0z0f = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_gracern8hroqfoa();

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-254.7,-117,509.5,234.1);


(lib.AvatarSkel_gracegb8e05ktm2 = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_grace17ekykc8dh();
	this.instance.setTransform(0,-0.1);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-445.2,-335.2,890.5,670.2);


(lib.AvatarSkel_gracea1zh5c2sj6 = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_graceozrojj3zk2();

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-452.1,-337.3,904.2,674.7);


(lib.AvatarSkel_grace47t3426hw5 = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_gracet01wjjbdvx();

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-314.4,-119.3,628.8,238.7);


(lib.AvatarSkel_grace1z6eptt8ue = function() {
	this.initialize();

	// 图层 1
	this.instance = new lib.AvatarSkel_gracex6vbdxjrjx();
	this.instance.setTransform(0,-0.1);

	this.addChild(this.instance);
}).prototype = p = new cjs.Container();
p.nominalBounds = new cjs.Rectangle(-495.7,-358.1,991.5,716.1);


(lib.AvatarSkel_walk = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{AvatarSkel_walk:0});

	// fronthand
	this.instance = new lib._1fronthand_1();
	this.instance.setTransform(-48.6,-395.5,0.986,0.98,48.4,0,0,26.4,22.8);

	this.timeline.addTween(cjs.Tween.get(this.instance).to({regY:22.6,scaleX:1,scaleY:0.99,rotation:46.4,x:-45.3,y:-416.9},4).to({regY:22.8,rotation:48.4,x:-48.7,y:-395.1},4).to({regY:22.6,rotation:46.4,x:-45.3,y:-416.9},4).to({regX:26.6,regY:22.7,scaleX:0.99,scaleY:0.99,rotation:47.4,x:-46.9,y:-406.2},1).wait(1));

	// frontshoulder
	this.instance_1 = new lib._2frontshoulder_1();
	this.instance_1.setTransform(26.2,-463.4,0.99,0.986,19.3,0,0,68.5,32.5);

	this.timeline.addTween(cjs.Tween.get(this.instance_1).to({regX:69,regY:32.4,scaleX:1,scaleY:0.99,rotation:17.3,x:27.2,y:-487.2},4).to({regX:68.5,regY:32.3,rotation:19.3,x:26.2,y:-463.1},4).to({regX:69,regY:32.4,rotation:17.3,x:27.2,y:-487.2},4).to({regX:68.8,regY:32.3,scaleX:1,scaleY:0.99,rotation:18.3,x:26.7,y:-475.4},1).wait(1));

	// weapon
	this.instance_2 = new lib._3weapon();
	this.instance_2.setTransform(-117.4,-308.9,0.985,0.98,-119.6,0,0,-14,32.6);

	this.timeline.addTween(cjs.Tween.get(this.instance_2).to({regX:-14.5,regY:32.9,scaleX:0.99,scaleY:0.99,rotation:-121.6,x:-110.9,y:-327.9},4).to({regX:-14.2,regY:32.7,rotation:-119.6,x:-117.4,y:-308.6},4).to({regX:-14.5,regY:32.9,rotation:-121.6,x:-110.9,y:-327.9},4).to({regX:-14.1,regY:32.6,scaleX:0.99,scaleY:0.99,rotation:-120.6,x:-114.1,y:-318.5},1).wait(1));

	// hair
	this.instance_3 = new lib._4headhair_1();
	this.instance_3.setTransform(133.4,-513.6,0.997,0.996,6.8,0,0,57,70.5);

	this.timeline.addTween(cjs.Tween.get(this.instance_3).to({regX:56.9,regY:70.6,scaleX:1,scaleY:1,x:133.1,y:-537.9},4).to({regX:57.1,regY:70.5,x:133.3,y:-513.3},4).to({x:133.2,y:-537.8},4).to({regX:57.2,scaleY:1,x:133.5,y:-525.6},1).wait(1));

	// head
	this.instance_4 = new lib._5headface_1();
	this.instance_4.setTransform(137.5,-511.9,0.997,0.996,6.8,0,0,41.6,52.9);

	this.timeline.addTween(cjs.Tween.get(this.instance_4).to({regX:41.5,regY:53.1,scaleX:1,scaleY:1,y:-536.1},4).to({y:-511.5},4).to({regX:41.6,y:-536},4).to({regX:41.5,scaleY:1,y:-523.8},1).wait(1));

	// robe
	this.instance_5 = new lib._6robe_1();
	this.instance_5.setTransform(11.2,-308.6,0.989,0.981,39.4,0,0,71.1,13.2);

	this.timeline.addTween(cjs.Tween.get(this.instance_5).to({regX:71.2,regY:13.6,scaleX:1,scaleY:0.99,y:-332.7},4).to({regX:71,regY:13.5,y:-308.3},4).to({y:-332.5},4).to({scaleX:0.99,scaleY:0.99,x:11.3,y:-320.6},1).wait(1));

	// frontfoot
	this.instance_6 = new lib._12backfoot_1();
	this.instance_6.setTransform(-174.8,-199.6,0.993,0.992,120.1,0,0,24.3,5.8);

	this.timeline.addTween(cjs.Tween.get(this.instance_6).wait(1).to({regX:24.1,regY:5.7,scaleX:1,scaleY:1,rotation:80.5,x:-137.9,y:-150.3},0).wait(1).to({regX:24.6,regY:6,scaleX:0.99,scaleY:0.99,rotation:40.6,x:-72,y:-102.8},0).wait(1).to({regX:24.3,regY:5.9,scaleX:1,scaleY:1,rotation:0.8,x:14.2,y:-97.7},0).wait(1).to({regX:24.1,regY:6,scaleX:1,scaleY:0.99,rotation:-38.8,x:98.8,y:-120.7},0).wait(1).to({regX:24.2,regY:5.9,scaleX:0.99,scaleY:0.99,rotation:-35.1,x:61.7,y:-105.6},0).wait(1).to({regY:5.8,scaleY:0.99,rotation:-31.1,x:31.4,y:-80.8},0).wait(1).to({regX:24.1,regY:5.9,scaleX:1,rotation:-27.1,x:-14.1,y:-61.4},0).wait(1).to({regY:6.1,scaleX:1,scaleY:0.99,rotation:-23,x:-65.2,y:-40.8},0).wait(1).to({regX:23.9,regY:6,scaleX:1,scaleY:1,rotation:5.3,x:-115.8,y:-69.1},0).wait(1).to({regX:24.1,regY:5.9,scaleX:0.99,scaleY:0.99,rotation:33.8,x:-182.4,y:-87.7},0).wait(1).to({regY:6,scaleX:1,scaleY:0.99,rotation:62.4,x:-235.8,y:-133.9},0).wait(1).to({regX:26.1,regY:7.6,scaleX:1,scaleY:1,rotation:90.7,x:-253.3,y:-202},0).wait(1).to({regX:24.2,regY:5.9,scaleX:1,scaleY:0.99,rotation:105.3,x:-216.1,y:-195},0).wait(1));

	// frontshin
	this.instance_7 = new lib._8frontshin_1();
	this.instance_7.setTransform(-35,-156.3,0.996,0.994,82,0,0,91.2,44.8);

	this.timeline.addTween(cjs.Tween.get(this.instance_7).wait(1).to({regX:75,regY:28.9,scaleX:0.99,scaleY:0.99,rotation:55.9,x:12.9,y:-177.4},0).wait(1).to({regX:75.5,regY:29,scaleY:0.99,rotation:29.6,x:49.8,y:-195.7},0).wait(1).to({scaleX:1,scaleY:1,rotation:3.5,x:82.3,y:-232.3},0).wait(1).to({regX:75.4,regY:28.7,scaleX:1,scaleY:0.99,rotation:-22.3,x:103.7,y:-269},0).wait(1).to({regX:75.3,scaleY:0.99,rotation:-12.8,x:92.2,y:-245.4},0).wait(1).to({regX:75.4,scaleX:1,scaleY:1,rotation:0,skewX:-3.5,skewY:-3.3,x:84.2,y:-216.3},0).wait(1).to({rotation:3.5,skewX:0,skewY:0,x:58.3,y:-196.9},0).wait(1).to({regX:75.3,regY:28.9,scaleX:1,scaleY:0.99,rotation:12,x:30.8,y:-168.6},0).wait(1).to({regX:75.2,regY:29.1,scaleX:1,scaleY:0.99,rotation:24,x:-0.3,y:-169.7},0).wait(1).to({regY:28.9,scaleX:0.99,scaleY:0.99,rotation:38.8,x:-46.2,y:-159.7},0).wait(1).to({regX:75.3,scaleY:0.99,rotation:50.6,x:-84.2,y:-177.9},0).wait(1).to({regX:75.5,regY:29,scaleX:1,scaleY:0.99,rotation:62.4,x:-119.2,y:-204.5},0).wait(1).to({regX:75,regY:28.7,scaleY:0.99,rotation:72.2,x:-79.3,y:-175.9},0).wait(1));

	// frontthigh
	this.instance_8 = new lib._9frontthigh_1();
	this.instance_8.setTransform(-21.6,-301.1,0.992,0.987,-22,0,0,68.1,26.4);

	this.timeline.addTween(cjs.Tween.get(this.instance_8).wait(1).to({regX:67.9,regY:26.5,scaleX:1,scaleY:0.99,rotation:-38.3,x:-20.9,y:-315.1},0).wait(1).to({regX:68,regY:26.4,scaleY:0.99,rotation:-54.4,x:-25.7,y:-318},0).wait(1).to({scaleX:1,scaleY:0.99,rotation:-70.5,x:-26.3,y:-328},0).wait(1).to({regY:26.3,scaleX:1,scaleY:1,rotation:-86.5,x:-26.8,y:-335.1},0).wait(1).to({regX:68.2,regY:26.1,scaleX:1,scaleY:0.99,rotation:-76,x:-26.2,y:-329.9},0).wait(1).to({regX:67.7,regY:26.4,scaleX:1,scaleY:0.99,rotation:-65.7,x:-18.5,y:-318.8},0).wait(1).to({regX:68.1,regY:26.1,scaleX:0.99,scaleY:0.99,rotation:-55.7,x:-23.8,y:-316.9},0).wait(1).to({regX:67.8,regY:26.3,scaleX:1,scaleY:0.99,rotation:-41.6,x:-23.2,y:-306.7},0).wait(1).to({regY:26.4,scaleX:0.99,rotation:-27.8,x:-21.4,y:-311.3},0).wait(1).to({regX:67.7,scaleX:1,scaleY:0.99,rotation:-11,x:-23.8,y:-307.6},0).wait(1).to({regX:67.8,regY:26.5,scaleX:1,scaleY:1,rotation:4,x:-26.6,y:-311.8},0).wait(1).to({regX:67.7,regY:26.2,scaleX:1,scaleY:0.99,rotation:18.8,x:-26.4,y:-323.8},0).wait(1).to({regX:67.9,regY:26.4,scaleX:1,scaleY:1,rotation:0,x:-23.8,y:-311.2},0).wait(1));

	// hip
	this.instance_9 = new lib._10hip_1();
	this.instance_9.setTransform(3.4,-304.7,0.989,0.985,23.8,0,0,55.5,37.5);

	this.timeline.addTween(cjs.Tween.get(this.instance_9).to({regX:55.4,regY:37.6,scaleX:1,scaleY:0.99,x:3.3,y:-328.7},4).to({regX:55.5,y:-304.2},4).to({y:-328.6},4).to({regY:37.5,scaleX:1,scaleY:0.99,x:3.2,y:-316.6},1).wait(1));

	// chest
	this.instance_10 = new lib._11chest_1();
	this.instance_10.setTransform(22.1,-310.9,0.986,0.98,35.8,0,0,87.7,212.8);

	this.timeline.addTween(cjs.Tween.get(this.instance_10).to({regX:88,scaleX:1,scaleY:0.99,x:22.2,y:-335.1},4).to({regY:213,y:-310.6},4).to({regY:212.9,y:-334.9},4).to({regY:212.8,scaleX:0.99,scaleY:0.99,x:22.1,y:-322.9},1).wait(1));

	// backfoot
	this.instance_11 = new lib._12backfoot_1();
	this.instance_11.setTransform(30.2,-46.2,0.991,0.986,-20.5,0,0,25.2,5);

	this.timeline.addTween(cjs.Tween.get(this.instance_11).wait(1).to({regY:4.9,scaleX:1,scaleY:1,rotation:0,x:-29.5,y:-64},0).wait(1).to({scaleX:1,scaleY:0.99,rotation:20.8,x:-85.9,y:-101.8},0).wait(1).to({regX:25.1,regY:4.8,scaleX:0.99,scaleY:0.99,rotation:41.6,x:-148,y:-122.7},0).wait(1).to({regX:24.9,regY:4.7,scaleX:1,scaleY:0.99,rotation:62.7,x:-210,y:-155.9},0).wait(1).to({regX:24.7,scaleY:0.99,rotation:74.2,x:-193.5,y:-148.2},0).wait(1).to({regX:25.5,regY:5.4,scaleX:1,scaleY:1,rotation:85.7,x:-192.5,y:-129.1},0).wait(1).to({regX:25,regY:4.9,scaleY:1,rotation:97,x:-173.3,y:-125.3},0).wait(1).to({scaleX:1,scaleY:0.99,rotation:108.5,x:-144.3,y:-146},0).wait(1).to({regY:4.7,scaleX:1,scaleY:1,rotation:83.2,x:-98.7,y:-93.5},0).wait(1).to({regX:25.1,regY:5,scaleX:0.99,scaleY:0.99,rotation:57.7,x:-42.1,y:-85.8},0).wait(1).to({regX:25.2,rotation:32.3,x:24.2,y:-87.2},0).wait(1).to({regX:25,regY:5.2,scaleX:1,scaleY:1,rotation:6.8,x:92.8,y:-85.4},0).wait(1).to({regY:4.9,scaleX:1,rotation:-6.8,x:58.8,y:-60.6},0).wait(1));

	// backshin
	this.instance_12 = new lib._13backshin_1();
	this.instance_12.setTransform(81.4,-192.1,0.989,0.984,26.3,0,0,38.5,10.9);

	this.timeline.addTween(cjs.Tween.get(this.instance_12).wait(1).to({regX:38.3,regY:11,scaleX:0.99,scaleY:0.99,rotation:33.8,x:37.3,y:-200},0).wait(1).to({regX:38.5,scaleY:0.99,rotation:41.4,x:-3.9,y:-227.7},0).wait(1).to({regY:10.9,rotation:48.6,x:-43.4,y:-245.6},0).wait(1).to({regX:38.6,regY:11.1,scaleX:1,scaleY:0.99,rotation:56.2,x:-91.3,y:-263.5},0).wait(1).to({regX:38.8,regY:11.2,scaleY:0.99,rotation:64.5,x:-61.6,y:-236.9},0).wait(1).to({scaleX:1,scaleY:0.99,rotation:72.7,x:-46.9,y:-199.3},0).wait(1).to({regX:38.5,regY:11,scaleX:1,scaleY:1,rotation:81,x:-20.4,y:-173.4},0).wait(1).to({regX:39.1,regY:11.5,scaleX:1,scaleY:1,rotation:89,x:18.2,y:-175.1},0).wait(1).to({regX:38.4,regY:11,scaleX:1,scaleY:0.99,rotation:73.2,x:49.8,y:-163.9},0).wait(1).to({regX:38.5,scaleX:0.99,scaleY:0.99,rotation:60.7,x:87.8,y:-185.4},0).wait(1).to({scaleY:0.99,rotation:46.4,x:120.7,y:-211.2},0).wait(1).to({regX:38.7,regY:11.1,scaleX:1,scaleY:0.99,rotation:32.1,x:156.7,y:-228.3},0).wait(1).to({regX:38.8,regY:11,scaleX:1,scaleY:0.99,rotation:29.3,x:116.4,y:-205.1},0).wait(1));

	// backthigh
	this.instance_13 = new lib._14backthigh_1();
	this.instance_13.setTransform(24.1,-302.6,0.994,0.992,-11.8,0,0,26.2,28.9);

	this.timeline.addTween(cjs.Tween.get(this.instance_13).wait(1).to({scaleX:1,scaleY:1,rotation:9.8,x:23,y:-316.2},0).wait(1).to({regX:26,regY:29.2,scaleX:1,scaleY:0.99,rotation:37.1,x:26.2,y:-314.1},0).wait(1).to({regX:26.3,scaleX:0.99,rotation:58.7,x:22.6,y:-317.5},0).wait(1).to({regX:26,regY:28.9,scaleX:1,scaleY:0.99,rotation:61.7,x:-11,y:-340.7},0).wait(1).to({regX:25.9,regY:29,scaleX:0.99,scaleY:0.99,rotation:60.9,x:22.9,y:-318.2},0).wait(1).to({scaleY:0.99,rotation:49.6,x:20.7,y:-304.1},0).wait(1).to({regX:26.2,regY:29.1,scaleY:0.99,rotation:34.6,x:23.4,y:-293.6},0).wait(1).to({regX:26.1,regY:28.9,scaleX:1,scaleY:0.99,rotation:23,x:26.8,y:-294},0).wait(1).to({regX:25.9,regY:29.1,scaleX:1,scaleY:1,rotation:6,x:27.9,y:-287.9},0).wait(1).to({regX:26.2,regY:28.9,scaleY:1,rotation:-10.3,x:31.3,y:-298.7},0).wait(1).to({regX:26,regY:29.1,scaleX:1,scaleY:0.99,rotation:-29.1,x:29.3,y:-300.9},0).wait(1).to({regX:25.8,regY:28.9,rotation:-44.6,x:41.2,y:-293.5},0).wait(1).to({regX:25.9,rotation:-30.8,x:23.3,y:-296.2},0).wait(1));

	// backrobe
	this.instance_14 = new lib._15backrobe_1();
	this.instance_14.setTransform(-8.8,-331.5,0.989,0.982,52.7,0,0,154.3,19);

	this.timeline.addTween(cjs.Tween.get(this.instance_14).to({regX:154.4,regY:19.2,scaleX:1,scaleY:0.99,y:-355.6},4).to({regX:154.5,regY:19.4,y:-331},4).to({regX:154.4,regY:19.3,y:-355.4},4).to({regX:154.5,regY:19.5,scaleX:1,scaleY:0.99,y:-343.4},1).wait(1));

	// backhand
	this.instance_15 = new lib._16backhand_1();
	this.instance_15.setTransform(36.2,-361.1,0.998,0.998,0,88.5,88.2,16.1,15.3);

	this.timeline.addTween(cjs.Tween.get(this.instance_15).to({regX:16.4,regY:15.6,rotation:86.5,skewX:0,skewY:0,x:39.6,y:-380.4},4).to({regX:15.8,regY:14.8,scaleX:1,rotation:88.2,x:36.4,y:-360.7},4).to({regX:16.4,regY:15.6,scaleX:1,rotation:86.5,x:39.6,y:-380.4},4).to({regX:18.5,regY:17.8,rotation:87.2,x:37.9,y:-370.8},1).wait(1));

	// backshoulder
	this.instance_16 = new lib._17backshoulder_1();
	this.instance_16.setTransform(127.4,-425.1,0.989,0.984,69.2,0,0,18.9,7);

	this.timeline.addTween(cjs.Tween.get(this.instance_16).to({scaleX:1,scaleY:0.99,rotation:67.7,x:128.6,y:-447.1},4).to({regY:6.9,scaleY:0.99,rotation:69.2,x:127.4,y:-424.6},4).to({regY:7,scaleY:0.99,rotation:67.7,x:128.6,y:-447.1},4).to({regX:18.7,regY:6.7,scaleX:0.99,rotation:68.5,x:128.1,y:-436},1).wait(1));

	// weaponOff
	this.instance_17 = new lib._3weapon();
	this.instance_17.setTransform(-36.4,-318.2,0.987,0.982,-120.3,0,0,-12.9,33.5);

	this.timeline.addTween(cjs.Tween.get(this.instance_17).to({regX:-13.1,regY:33.6,scaleX:1,scaleY:0.99,rotation:-121.8,x:-32.2,y:-335.3},4).to({regX:-12.8,regY:33.5,rotation:-120.3,x:-36.6,y:-317.9},4).to({regX:-13.1,regY:33.6,rotation:-121.8,x:-32.2,y:-335.3},4).to({regX:-12.9,regY:33.5,scaleX:1,scaleY:0.99,rotation:-121.1,x:-34.3,y:-326.8},1).wait(1));

	// cape
	this.instance_18 = new lib._19cape_1();
	this.instance_18.setTransform(68.3,-474.9,0.997,0.996,84.5,0,0,185.8,3.1);

	this.timeline.addTween(cjs.Tween.get(this.instance_18).to({regX:186.3,regY:3.6,scaleX:1,scaleY:1,x:68.1,y:-499.1},4).to({x:68.2,y:-474.6},4).to({regX:186.4,y:-498.9},4).to({regX:185.9,regY:3.1,scaleY:1,y:-486.8},1).wait(1));

	// backhair
	this.instance_19 = new lib._20backhair_1();
	this.instance_19.setTransform(81.7,-597.7,0.99,0.985,65,0,0,89.7,8.8);

	this.timeline.addTween(cjs.Tween.get(this.instance_19).to({regX:89.5,regY:8.7,scaleX:1,scaleY:0.99,x:81.6,y:-621.8},4).to({regY:8.8,x:81.5,y:-597.4},4).to({y:-621.8},4).to({regX:89.6,scaleX:1,scaleY:0.99,x:81.6,y:-609.8},1).wait(1));

	// shadow
	this.instance_20 = new lib.diying();
	this.instance_20.setTransform(0,29.3,1,1,0,0,0,200,57.5);

	this.timeline.addTween(cjs.Tween.get(this.instance_20).wait(14));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-548.2,-681.8,748.2,768.7);


(lib.AvatarSkel_twokeep_attack3 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{AvatarSkel_twokeep_attack3:0});

	// effect1
	this.instance = new lib.AvatarSkel_gracer86kyi0z0f();
	this.instance.setTransform(-646.2,-182.1);

	this.instance_1 = new lib.AvatarSkel_grace47t3426hw5();
	this.instance_1.setTransform(-586.6,-179.8);

	this.instance_2 = new lib.AvatarSkel_gracey7qgfcvsnv();
	this.instance_2.setTransform(-467.7,-175.7);

	this.instance_3 = new lib.AvatarSkel_gracex8iavwo1pu();
	this.instance_3.setTransform(87.5,-250.2);

	this.instance_4 = new lib.AvatarSkel_graces1ui2jwpjl();
	this.instance_4.setTransform(97.4,-250.2);

	this.instance_5 = new lib.AvatarSkel_gracez2avpshr9j();
	this.instance_5.setTransform(107.3,-250.2);

	this.instance_6 = new lib.AvatarSkel_gracexjqeglzfjo();
	this.instance_6.setTransform(117.2,-250.2);

	this.instance_7 = new lib.AvatarSkel_grace1z6eptt8ue();
	this.instance_7.setTransform(160.2,-250.6);

	this.instance_8 = new lib.元件1();
	this.instance_8.setTransform(238.7,-243.1,1,1,0,0,0,486.5,358);

	this.instance_9 = new lib.AvatarSkel_gracea1zh5c2sj6();
	this.instance_9.setTransform(291.9,-239.7);

	this.instance_10 = new lib.AvatarSkel_gracegb8e05ktm2();
	this.instance_10.setTransform(324,-236.9);

	this.instance_11 = new lib.AvatarSkel_gracez13aevqqpz();
	this.instance_11.setTransform(334.4,-233.9);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[]}).to({state:[{t:this.instance}]},9).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).to({state:[{t:this.instance_9}]},1).to({state:[{t:this.instance_10}]},1).to({state:[{t:this.instance_11}]},1).to({state:[]},1).wait(1));

	// fronthand
	this.instance_12 = new lib._1fronthand_1();
	this.instance_12.setTransform(-44.9,-372.1,0.999,0.999,-84.3,0,0,26.6,22.7);

	this.timeline.addTween(cjs.Tween.get(this.instance_12).to({regY:22.8,scaleX:1,scaleY:1,rotation:-74.4,x:-98.6,y:-361.9},3,cjs.Ease.get(-1)).to({regX:26.7,regY:22.7,rotation:-37.2,x:-227.2,y:-334},3).to({regY:22.8,scaleX:1,scaleY:1,rotation:5.2,x:-341.3,y:-329.7},3).to({rotation:10.9,x:-184.4,y:-341.5},1).to({scaleX:1,scaleY:1,rotation:-50.1,x:58.9,y:-351.6},1).to({regY:22.7,scaleX:1,scaleY:1,rotation:-81.4,x:242.4,y:-355},1).to({regX:26.6,rotation:-89.4,x:249.8,y:-371.1},3).to({regX:26.7,scaleX:1,scaleY:1,rotation:-104.3,x:174.6,y:-390.6},1).to({rotation:-117.6,x:80.1,y:-400.3},1).to({regX:26.6,regY:22.8,scaleX:1,scaleY:1,rotation:-130.8,x:-13.4,y:-388.1},1).to({regY:22.7,rotation:-84.3,x:-44.9,y:-372.1},3).wait(1));

	// frontshoulder
	this.instance_13 = new lib._2frontshoulder_1();
	this.instance_13.setTransform(-57.8,-460.1,0.999,0.999,-35.8,0,0,68.7,32.5);

	this.timeline.addTween(cjs.Tween.get(this.instance_13).to({regY:32.4,scaleX:1,scaleY:1,rotation:-37.3,x:-116.4,y:-453.1},3,cjs.Ease.get(-1)).to({regX:68.6,rotation:-25,x:-225.1,y:-432.7},3).to({regX:68.5,regY:32.6,scaleX:1,scaleY:1,rotation:-7.7,x:-305.7,y:-431.8},3).to({regY:32.5,scaleX:1,scaleY:1,rotation:-20.3,x:-169.9,y:-442.1},1).to({regX:68.6,rotation:-59.7,x:2.5,y:-437.8},1).to({scaleX:1,scaleY:1,rotation:-89.3,x:151.3,y:-401.4},1).to({regX:68.5,rotation:-97.3,x:153.1,y:-404.6},3).to({regX:68.6,rotation:-83,x:94.1,y:-442.9},1).to({regY:32.4,scaleX:1,scaleY:1,rotation:-66.7,x:25,y:-469.8},1).to({regX:68.7,regY:32.5,scaleX:1,scaleY:1,rotation:-50.5,x:-49.6,y:-474.4},1).to({rotation:-35.8,x:-57.8,y:-460.1},3).wait(1));

	// weapon
	this.instance_14 = new lib._3weapon();
	this.instance_14.setTransform(50.6,-359.3,0.998,0.998,-1.3,0,0,-14.1,32.8);

	this.timeline.addTween(cjs.Tween.get(this.instance_14).to({scaleX:1,scaleY:1,rotation:11,x:46.6,y:-357},1,cjs.Ease.get(-1)).to({regX:-14,scaleX:1,scaleY:1,rotation:48.6,x:26.2,y:-361.6},1).to({regX:-14.1,scaleX:1,scaleY:1,rotation:99.4,x:12.4,y:-351.7},1).to({regX:-14,scaleX:1,scaleY:1,rotation:162.1,x:-136.5,y:-253.9},3).to({rotation:230.5,x:-334.8,y:-200.8},3).to({regX:-14.1,scaleX:1,scaleY:1,rotation:241.2,x:-215,y:-205.3},1).to({regX:-14,regY:32.7,rotation:234,x:155.5,y:-270.8},1).to({regY:32.9,scaleX:1,scaleY:1,rotation:406,x:336.9,y:-359},1).to({regY:32.8,rotation:398.1,x:342.8,y:-388.4},3).to({regY:32.9,rotation:375.5,x:257,y:-419.1},1).to({rotation:357.7,x:156.6,y:-452.8},1).to({regX:-14.1,regY:32.8,rotation:347.4,x:52.3,y:-449.6},1).to({scaleX:1,scaleY:1,rotation:358.7,x:50.6,y:-359.3},3).wait(1));

	// hair
	this.instance_15 = new lib._4headhair_1();
	this.instance_15.setTransform(7.1,-569.4,1,1,-3.5,0,0,57,70.5);

	this.timeline.addTween(cjs.Tween.get(this.instance_15).to({rotation:-15,x:-68.9,y:-571.7},3,cjs.Ease.get(-1)).to({regX:57.1,rotation:-25.2,x:-186,y:-556.7},3).to({regX:57,rotation:-30.1,x:-264.3,y:-558.9},3).to({rotation:-4,x:-92.3,y:-547.9},1).to({scaleX:1,scaleY:1,rotation:22,x:89.8,y:-509.6},1).to({regX:57.1,scaleX:1,scaleY:1,rotation:48.1,x:255.3,y:-426.2},1).wait(3).to({regX:57,rotation:-3.5,x:12.8,y:-587.3},3).to({x:7.1,y:-569.4},3).wait(1));

	// head
	this.instance_16 = new lib._5headface_1();
	this.instance_16.setTransform(11.6,-569.2,1,1,-3.5,0,0,41.5,53);

	this.timeline.addTween(cjs.Tween.get(this.instance_16).to({regX:41.6,regY:52.9,rotation:-15,x:-64.4,y:-572.4},3,cjs.Ease.get(-1)).to({regX:41.5,regY:53,rotation:-25.2,x:-181.6,y:-558},3).to({regY:53.1,rotation:-30.1,x:-260.1,y:-560.5},3).to({regY:53,rotation:-4,x:-88.8,y:-547.9},1).to({regY:53.1,scaleX:1,scaleY:1,rotation:22,x:92.9,y:-507.6},1).to({regY:53,scaleX:1,scaleY:1,rotation:48.1,x:257.9,y:-422.5},1).wait(3).to({rotation:-3.5,x:17.3,y:-587.1},3).to({x:11.6,y:-569.2},3).wait(1));

	// robe
	this.instance_17 = new lib._6robe_1();
	this.instance_17.setTransform(28.8,-337.1,1,1,-3,0,0,71,13.7);

	this.timeline.addTween(cjs.Tween.get(this.instance_17).to({regX:71.1,rotation:-1.6,x:-3.5,y:-337.4},3,cjs.Ease.get(-1)).to({regX:71,rotation:-20.6,x:-93.5,y:-341.1},3).to({regX:71.1,regY:13.6,rotation:-22.6,x:-162.4,y:-345.9},3).to({regX:71,rotation:48.6,x:86.8,y:-265},3).wait(3).to({regY:13.7,rotation:-3,x:34.5,y:-355},3).to({x:28.8,y:-337.1},3).wait(1));

	// idlefoot
	this.instance_18 = new lib._7idlefoot_1();
	this.instance_18.setTransform(-152.2,-45.6,1,1,0,0,0,30.3,9);

	this.timeline.addTween(cjs.Tween.get(this.instance_18).to({x:-179.4,y:-45.7},3,cjs.Ease.get(-1)).to({x:-239.9,y:-45.8},3).to({x:-270.1,y:-45.9},1).to({x:-300.3,y:-46},2).to({x:-196.4,y:-67},3).wait(3).to({x:-152.4,y:-46},3).to({x:-152.2,y:-45.6},3).wait(1));

	// frontshin
	this.instance_19 = new lib._8frontshin_1();
	this.instance_19.setTransform(-54.6,-163.9,0.999,0.999,15.5,0,0,75.5,28.9);

	this.timeline.addTween(cjs.Tween.get(this.instance_19).to({scaleX:1,scaleY:1,x:-81.9,y:-164.4},3,cjs.Ease.get(-1)).to({regY:28.8,x:-142.6,y:-165.6},3).to({regX:75.4,regY:28.9,scaleX:1,scaleY:1,x:-203.4,y:-166.8},3).to({rotation:28.5,x:-73.8,y:-163.5},3).wait(3).to({rotation:4.8,x:-77.8,y:-181.2},3).to({regX:75.5,rotation:15.5,x:-54.6,y:-163.9},3).wait(1));

	// frontthigh
	this.instance_20 = new lib._9frontthigh_1();
	this.instance_20.setTransform(-15.5,-304.3,1,1,-3.6,0,0,68,26.4);

	this.timeline.addTween(cjs.Tween.get(this.instance_20).to({scaleX:1,scaleY:1,rotation:-5.3,x:-48.3,y:-304.7},3,cjs.Ease.get(-1)).to({rotation:-9.3,x:-121,y:-305.8},3).to({scaleX:1,scaleY:1,rotation:-13.3,x:-193.9,y:-306.8},3).to({rotation:26.9,x:22.6,y:-268.4},3).to({rotation:26.9},3).to({regX:67.8,regY:26.3,rotation:9.1,x:-17.6,y:-308.4},3).to({regX:68,regY:26.4,rotation:-3.6,x:-15.5,y:-304.3},3).wait(1));

	// hip
	this.instance_21 = new lib._10hip_1();
	this.instance_21.setTransform(8.6,-310.2,1,1,-3.5,0,0,55.5,37.6);

	this.timeline.addTween(cjs.Tween.get(this.instance_21).to({regX:55.6,rotation:-2.1,x:-24.4,y:-311},3,cjs.Ease.get(-1)).to({regX:55.5,rotation:-21.1,x:-104.6,y:-309.3},3).to({regX:55.6,regY:37.5,rotation:-23.2,x:-172.4,y:-313.7},3).to({regX:55.4,regY:37.6,rotation:48.1,x:53,y:-264.1},3).to({rotation:48.1},3).to({regX:55.5,rotation:-3.5,x:14.3,y:-328.1},3).to({x:8.6,y:-310.2},3).wait(1));

	// chest
	this.instance_22 = new lib._11chest_1();
	this.instance_22.setTransform(25.5,-337.2,1,1,-3.5,0,0,88,212.6);

	this.timeline.addTween(cjs.Tween.get(this.instance_22).to({rotation:-13.5,x:-9.1,y:-346.2},3,cjs.Ease.get(-1)).to({regX:87.9,rotation:-21.1,x:-96.8,y:-340.1},3).to({regX:88,rotation:-23.2,x:-165.6,y:-344.8},3).to({rotation:48.1,x:84.7,y:-267.6},3).to({rotation:48.1},3).to({rotation:-3.5,x:31.2,y:-355.1},3).to({x:25.5,y:-337.2},3).wait(1));

	// backfoot
	this.instance_23 = new lib._12backfoot_1();
	this.instance_23.setTransform(91.7,-55.6,1,1,0,0,0,25.2,5);

	this.timeline.addTween(cjs.Tween.get(this.instance_23).to({x:80.2,y:-55.7},3,cjs.Ease.get(-1)).to({x:54.7,y:-55.8},3).to({x:29.2,y:-56},3).to({x:91},3).wait(3).to({x:90.4},3).to({x:91.7,y:-55.6},3).wait(1));

	// backshin
	this.instance_24 = new lib._13backshin_1();
	this.instance_24.setTransform(112.4,-205.4,0.999,0.999,17,0,0,38.5,11);

	this.timeline.addTween(cjs.Tween.get(this.instance_24).to({rotation:9.8,x:81.7,y:-204.3},3,cjs.Ease.get(-1)).to({scaleX:1,scaleY:1,rotation:-5.8,x:13.3,y:-201.8},3).to({scaleX:1,scaleY:1,rotation:-21.4,x:-55.1,y:-199.4},3).to({rotation:37,x:171.2,y:-192.5},3).wait(3).to({rotation:9.1,x:91.7,y:-219.5},3).to({rotation:17,x:112.4,y:-205.4},3).wait(1));

	// backthigh
	this.instance_25 = new lib._14backthigh_1();
	this.instance_25.setTransform(36.3,-307.5,1,1,-22.4,0,0,26,29.1);

	this.timeline.addTween(cjs.Tween.get(this.instance_25).to({scaleX:1,scaleY:1,rotation:-22.5,x:5.5,y:-304.7},3,cjs.Ease.get(-1)).to({rotation:-22.8,x:-62.9,y:-298.9},3).to({regX:25.8,scaleX:1,scaleY:1,rotation:-23.3,x:-131.2,y:-293.2},3).to({regX:25.9,rotation:-44.8,x:62.6,y:-255.6},3).wait(3).to({regX:26,regY:29.2,rotation:-12.1,x:36.3,y:-333.7},3).to({regY:29.1,rotation:-22.4,y:-307.5},3).wait(1));

	// backrobe
	this.instance_26 = new lib._15backrobe_1();
	this.instance_26.setTransform(-15.8,-330.1,1,1,1.5,0,0,154.4,19.1);

	this.timeline.addTween(cjs.Tween.get(this.instance_26).to({rotation:2.8,x:-48.3,y:-331.3},3,cjs.Ease.get(-1)).to({regY:19.2,scaleX:1,scaleY:1,rotation:-16.1,x:-133.8,y:-320.9},3).to({regX:154.5,regY:19.1,scaleX:1,scaleY:1,rotation:-18.1,x:-202,y:-324.2},3).to({regX:154.3,rotation:65.1,x:53.5,y:-295.6},3).to({regY:19.2,rotation:52.9,x:53.4},3).to({regX:154.4,regY:19.1,rotation:27,x:-10,y:-348},3).to({rotation:1.5,x:-15.8,y:-330.1},3).wait(1));

	// backhand
	this.instance_27 = new lib._16backhand_1();
	this.instance_27.setTransform(54.6,-395.2,0.998,0.998,-45.1,0,0,16.8,15.8);

	this.timeline.addTween(cjs.Tween.get(this.instance_27).to({regY:15.7,scaleX:1,scaleY:1,rotation:-54.9,x:84.6,y:-388.1},1,cjs.Ease.get(-1)).to({regY:15.8,scaleX:1,scaleY:1,rotation:-84.7,x:97.9,y:-435.7},1).to({scaleX:1,scaleY:1,rotation:-145.7,x:49.5,y:-547.7},1).to({scaleX:1,scaleY:1,rotation:-174.9,x:-116.2,y:-583.2},3).to({regX:16.6,regY:15.7,scaleX:1,scaleY:1,rotation:-198.7,x:-298.1,y:-568.2},3).to({regX:16.7,scaleX:1,scaleY:1,rotation:-144.8,x:-16.5,y:-562.7},1).to({regX:16.8,regY:15.8,rotation:-82.9,x:161.7,y:-424.4},1).to({regX:16.9,scaleX:1,scaleY:1,rotation:-65.8,x:294.8,y:-330.8},1).to({rotation:-71.8,x:292.6,y:-334},3).to({scaleX:1,scaleY:1,rotation:-35.6,x:141.3,y:-366.9},1).to({regY:15.7,rotation:-43.1,x:83.5,y:-383},1).to({regX:16.7,regY:15.8,scaleX:1,scaleY:1,rotation:-50.8,x:37.5,y:-396.1},1).to({regX:16.8,rotation:-45.1,x:54.6,y:-395.2},3).wait(1));

	// backshoulder
	this.instance_28 = new lib._17backshoulder_1();
	this.instance_28.setTransform(33.1,-487.6,1,1,3.7,0,0,18.9,6.9);

	this.timeline.addTween(cjs.Tween.get(this.instance_28).to({scaleX:1,scaleY:1,rotation:-8.8,x:29.6,y:-484.1},1,cjs.Ease.get(-1)).to({scaleX:1,scaleY:1,rotation:-46.6,x:-4.8,y:-483.1},1).to({scaleX:1,scaleY:1,rotation:-120.8,x:-24.5,y:-465.6},1).to({regY:6.8,rotation:-172.6,x:-99,y:-466.6},3).to({regY:6.9,scaleX:1,scaleY:1,rotation:-219.2,x:-188.3,y:-478.5},3).to({regY:7,scaleX:1,scaleY:1,rotation:-155.9,x:-35.7,y:-441.7},1).to({scaleX:1,scaleY:1,rotation:-95.5,x:60.4,y:-388.2},1).to({regY:6.9,scaleX:1,scaleY:1,rotation:-73,x:187,y:-335.1},1).to({rotation:-79,x:184.9,y:-327},3).to({scaleX:1,scaleY:1,rotation:-14.6,x:83.8,y:-460.8},1).to({regY:6.8,rotation:1,x:61,y:-481.8},1).to({regY:6.9,scaleX:1,scaleY:1,rotation:2.2,x:38.2,y:-502.8},1).to({rotation:3.7,x:33.1,y:-487.6},3).wait(1));

	// weaponOff
	this.instance_29 = new lib._3weapon();
	this.instance_29.setTransform(137.2,-365,0.998,0.998,30.4,0,0,-12.7,33.5);

	this.timeline.addTween(cjs.Tween.get(this.instance_29).to({scaleX:1,scaleY:1,rotation:21.1,x:162.3,y:-369.6},1,cjs.Ease.get(-1)).to({scaleX:1,scaleY:1,rotation:-6.3,x:181.6,y:-462.7},1).to({regX:-12.8,regY:33.6,rotation:-63.7,x:70.2,y:-628.9},1).to({regY:33.5,scaleX:1,scaleY:1,rotation:-78.6,x:-142.4,y:-658.3},3).to({regX:-12.9,regY:33.4,scaleX:1,scaleY:1,rotation:-88.2,x:-362,y:-629.6},3).to({regX:-12.8,regY:33.5,rotation:-53,x:-0.9,y:-650.2},1).to({regX:-12.7,scaleX:1,scaleY:1,rotation:-48.8,x:255.5,y:-441.7},1).to({scaleX:1,scaleY:1,rotation:91.1,x:399.4,y:-343.4},1).to({rotation:85.1,x:395.3,y:-357.4},3).to({regX:-12.8,regY:33.6,rotation:56.5,x:217.4,y:-323.5},1).to({scaleX:1,scaleY:1,rotation:40.5,x:162.1,y:-345},1).to({regX:-12.7,regY:33.5,scaleX:1,scaleY:1,rotation:26.2,x:119.6,y:-367.2},1).to({rotation:30.4,x:137.2,y:-365},3).wait(1));

	// cape
	this.instance_30 = new lib._19cape_1();
	this.instance_30.setTransform(-36.3,-497,1,1,4.5,0,0,185.8,3.1);

	this.timeline.addTween(cjs.Tween.get(this.instance_30).to({regY:3,scaleX:1,scaleY:1,rotation:8.1,x:-87.7,y:-488.7},3,cjs.Ease.get(-1)).to({scaleX:1,scaleY:1,rotation:32,x:-168.3,y:-467.4},3).to({scaleX:1,scaleY:1,rotation:61.1,x:-217.1,y:-469.1},3).to({regY:3.1,rotation:113.8,x:180.6,y:-388.6},3).to({regY:3,rotation:94.3,x:180.7},3).to({regY:3.1,rotation:37.9,x:-22.7,y:-498.1},3).to({rotation:4.5,x:-36.3,y:-497},3).wait(1));

	// backhair
	this.instance_31 = new lib._20backhair_1();
	this.instance_31.setTransform(-29.7,-609.9,1,1,-3.5,0,0,89.8,8.8);

	this.timeline.addTween(cjs.Tween.get(this.instance_31).to({scaleX:1,scaleY:1,rotation:0.3,x:-111.3,y:-596.7},3,cjs.Ease.get(-1)).to({regX:89.7,scaleX:1,scaleY:1,rotation:24.5,x:-225.5,y:-558.4},3).to({regX:89.8,scaleX:1,scaleY:1,rotation:53.8,x:-295.7,y:-542.3},3).to({scaleX:1,scaleY:1,rotation:76.7,x:-117.5,y:-545.1},1).to({regY:8.7,rotation:99,x:71.1,y:-520.5},1).to({regX:89.9,regY:8.8,scaleX:1,scaleY:1,rotation:121.8,x:243.1,y:-451},1).to({rotation:105.6,y:-450.9},3).to({regX:89.8,rotation:36.9,x:-24,y:-612.4},3).to({rotation:-3.5,x:-29.7,y:-609.9},3).wait(1));

	// effect2
	this.instance_32 = new lib.shape316("synched",0);
	this.instance_32.setTransform(-463,-934.6,4.59,4.59,0,0,0,-67.5,-133.6);

	this.instance_33 = new lib.shape317("synched",0);
	this.instance_33.setTransform(-403.8,-935.1,4.59,4.59,0,0,0,-54.6,-133.7);

	this.instance_34 = new lib.shape318("synched",0);
	this.instance_34.setTransform(-283.6,-933.7,4.59,4.59,0,0,0,-28.4,-133.4);

	this.instance_35 = new lib.shape286("synched",0);
	this.instance_35.setTransform(146.8,-533.6,0.331,0.593,-8,0,0,1044.3,42.1);
	this.instance_35._off = true;

	this.instance_36 = new lib.shape287("synched",0);
	this.instance_36.setTransform(305.9,-535.6,0.331,0.593,-8,0,0,1082.2,42.1);

	this.instance_37 = new lib.shape288("synched",0);
	this.instance_37.setTransform(358.1,-536.3,0.331,0.593,-8,0,0,1101.3,42.2);

	this.instance_38 = new lib.shape289("synched",0);
	this.instance_38.setTransform(389.7,-537,0.331,0.593,-8,0,0,1113.8,42.1);

	this.instance_39 = new lib.shape290("synched",0);
	this.instance_39.setTransform(401.3,-537.1,0.331,0.593,-8,0,0,1120.2,42.1);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[]}).to({state:[{t:this.instance_32}]},9).to({state:[{t:this.instance_33}]},1).to({state:[{t:this.instance_34}]},1).to({state:[{t:this.instance_35}]},1).to({state:[{t:this.instance_35}]},1).to({state:[{t:this.instance_35}]},1).to({state:[{t:this.instance_35}]},1).to({state:[{t:this.instance_35}]},1).to({state:[{t:this.instance_36}]},1).to({state:[{t:this.instance_37}]},1).to({state:[{t:this.instance_38}]},1).to({state:[{t:this.instance_39}]},1).to({state:[]},1).wait(1));
	this.timeline.addTween(cjs.Tween.get(this.instance_35).wait(12).to({_off:false},0).wait(1).to({x:156.8},0).wait(1).to({x:166.6},0).wait(1).to({x:176.5},0).wait(1).to({x:229.2,y:-533.8},0).to({_off:true},1).wait(5));

	// shadow
	this.instance_40 = new lib.diying("synched",0);
	this.instance_40.setTransform(-2.1,12.1,1,1,0,0,0,197.9,57.1);

	this.timeline.addTween(cjs.Tween.get(this.instance_40).wait(22));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-261.4,-820.1,699,890.1);

})(lib = lib||{}, images = images||{}, createjs = createjs||{});
var lib, images, createjs;