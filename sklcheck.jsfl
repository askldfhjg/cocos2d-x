
var file = fl.configURI + 'Commands/json2.jsfl';
fl.runScript(file); 

var mainTag = {
	"AvatarSkelM" : "idle",
};
var attackTag = {
	"twokeep" : {
		"4" :[20, 21, 32, 33, 43, 44, 52, 53, 71, 72],
		"3" :[11, 12],
		"2" :[10, 11, 19, 20],
		"1" :[10, 11],
	},
	"sword" : {
		"5" :[7, 8, 15, 16, 24, 25, 33, 34, 42, 43],
		"4" :[4, 5, 8, 9, 13, 14, 24, 25],
		"3" :[5, 6],
		"2" :[4, 5],
		"1" :[5, 6],
	},
	"combat" : {
		"5" :[26, 27, 37, 38, 44, 45, 51, 52, 56, 57, 61 ,62, 67, 68, 74, 86],
		"4" :[],
		"3" :[6, 7],
		"2" :[8, 9],
		"1" :[5, 6],
	},
	"bigsword" : {
		"5" :[14, 15, 31, 32, 50, 51, 64, 65,],
		"4" :[21, 22, 34, 35, 46, 47, 79, 80],
		"3" :[8, 9],
		"2" :[18, 19],
		"1" :[18, 19],
	},
};
var otherTag = {
	"heal" : {
		13 : "_addHp",
	},
	"add_def" :{
		16 : "_addDef",
	},
};
var boneName = ["fronthand",
				"frontshoulder",
				"weapon",
				"hair",
				"head",
				"robe",
				"frontfoot",
				"idlefoot",
				"frontshin",
				"frontthigh",
				"hip",
				"chest",
				"backfoot",
				"backshin",
				"backthigh",
				"backrobe",
				"backhand",
				"backshoulder",
				"weaponoff",
				"cape",
				"backhair",
				"shadow"];
var actionList = {};
var spriteList = {};
var exportPng = [];
var startFrameStatus = {};
var startIndex = 0;
var output = {};
var select = fl.getDocumentDOM().selection;
var lll = select.length;
fl.showIdleMessage(false);
var skillEffectCount = 1;
var addattackTag = confirm("add attack tag");
for(var i =0;i < lll;i++)
{
	var elem = select[i];
	fl.trace(elem.libraryItem.name)
	setTransformationPointForElement(elem, {x:0, y:0});
	fl.getDocumentDOM().selectNone();
	elem.selected = true;
	fl.getDocumentDOM().enterEditMode('inPlace');
	var asName = elem.libraryItem.linkageClassName;
	if(asName == null)
	{
		elem.libraryItem.linkageClassName = elem.libraryItem.name;
		asName = elem.libraryItem.name;
	}
	getActionList(boneName, asName);
	fl.getDocumentDOM().exitEditMode();
	fl.trace("-------------------------------------");
}
fl.showIdleMessage(true);
fl.trace(attackInfo(output));

function getActionList(boneName, asName)
{
	var timeline = fl.getDocumentDOM().getTimeline();
	var layers = timeline.layers;
	var labelEnd = 0;
	var maxFrameId = 0;
	var boneOtherLayer = 1;
	var labelLayer = null;
	var effectLayerFrameCount = [];
	var flag = false;
	var maskCount = 0;
	for(var layerIndex = 0; layerIndex < layers.length; layerIndex++) {
		var currentLayer = layers[layerIndex];
		var name = currentLayer.name.toLowerCase();
		currentLayer.locked = false;
		if(!currentLayer.visible) {
			if(inArray(boneName, name))
			{
				fl.trace(asName+" "+name+" 不可见");
				currentLayer.visible = true;
			}
			if(currentLayer.layerType == "mask")
			{
				fl.trace(asName+" "+name+" 不可见");
				currentLayer.visible = true;
			}
			continue;
		}
		if(currentLayer.layerType == "mask")
		{
			maskCount++;
			if(maskCount > 1)
			{
				fl.trace("mask层大于1,手动删除先");
				continue;
			}
		}
		var frames = currentLayer.frames;
		var llName = currentLayer.name.toLowerCase();
		if(llName.search("label") != -1) {
			timeline.setSelectedLayers(layerIndex, true);
			timeline.clearKeyframes(0, frames.length - 1);
			frames = currentLayer.frames;
			if(mainTag.hasOwnProperty(asName))
			{
				asName = mainTag[asName];
			}
			getLabelXml(frames, asName);
			labelEnd = frames.length - 1;
			labelLayer = layerIndex;
			currentLayer.name = "label";
			continue;
		}
		if(currentLayer.name.toLowerCase() == "shadow") {
			continue;
		}
		if(currentLayer.layerType == "mask")
		{
			currentLayer.name = "masklayer";
			getFrameXML(labelLayer, currentLayer, asName, flag, true);
		}
		else
		{
			if(!inArray(boneName, name))
			{
				if(boneOtherLayer >= 4)
				{
					fl.trace(asName+" attacklayer over count");
				}
				currentLayer.name = "effect" + boneOtherLayer;
				
				getFrameXML(labelLayer, currentLayer, asName, flag, false);
				flag = true
				boneOtherLayer++;
				effectLayerFrameCount.push(layerIndex);
			}
		}

		if((frames.length - 1) > maxFrameId)
		{
			maxFrameId = frames.length - 1;
		}
		
	}
	if(maxFrameId > labelEnd)
	{
		fl.trace(asName+" label 少了");
	}
	for(var i = 0;i<effectLayerFrameCount.length;i++)
	{
		if(maxFrameId > layers[effectLayerFrameCount[i]].frames.length - 1)
		{
			fl.trace("effect"+(i+1)+" 帧少了");
			selectLayer(effectLayerFrameCount[i]);
			timeline.insertBlankKeyframe(layers[effectLayerFrameCount[i]].frames.length)
			selectFrame(maxFrameId);
			timeline.insertFrames();
		}
	}
}

function getFrameXML(labelLayerId, currentLayer, asName, flagggg, maskLayer) {

	var frames = currentLayer.frames;
	var ccc = frames.length;
	var flag = false;
	if(frames[0].elements.length >0)
	{
		flag = true;
	}
	for(var f=0;f<ccc;)
	{
		var frame = frames[f];
		var end = frame.startFrame + frame.duration;
		if(end >= ccc)
		{
			break;
		}
		if(frames[end].elements.length <= 0 && flag)
		{
			flag = false;
		}
		else if(frames[end].elements.length > 0 && !flag)
		{
			flag = true;
		}
		f = end
	}
	var timeline = fl.getDocumentDOM().getTimeline();
	timeline.setSelectedLayers(labelLayerId, true);
	var labelLayer = timeline.layers[labelLayerId];
	var labelframes = labelLayer.frames;
	var info = asName.split("_");

	if(addattackTag)
	{
		if(attackTag.hasOwnProperty(info[0]))
		{
			if(attackTag[info[0]].hasOwnProperty(info[2]) && !flagggg)
			{
				var keyframe = attackTag[info[0]][info[2]];
				for(var i = 0; i < keyframe.length; i++)
				{
					if(i == 0)
					{
						continue;
					}
					timeline.convertToKeyframes(keyframe[i]);
				}
				
				var labelframes = labelLayer.frames;
				for(var i = 0; i < keyframe.length; i++)
				{
					var t = i % 2;
					var ll = parseInt(i/2);
					if(t == 0)
					{
						if(i == 0)
						{
							labelframes[0].name = asName + "Attack" + (ll+1);
						}
						else
						{
							labelframes[keyframe[i]].name = asName + "Attack" + (ll+1);
						}
					}
					else
					{
						labelframes[keyframe[i]].name = asName + "Attack" + (ll+1) + "Hit";
					}
				}
				if(!output.hasOwnProperty(info[0]))
				{
					output[info[0]] = {};
				}
				var cc = keyframe.length / 2;
				if(!output[info[0]].hasOwnProperty(cc))
				{
					output[info[0]][cc] = [];
				}
				output[info[0]][cc].push(asName);
			}
		}

		if(otherTag.hasOwnProperty(asName))
		{
			for(var nn in otherTag[asName])
			{
				var ff = parseInt(nn);
				timeline.convertToKeyframes(ff);
				labelLayer.frames[ff].name = asName + otherTag[asName][nn];
			}

		}
	}

	for(var f=0;f<ccc;)
	{
		if(frames[f].elements.length > 0)
		{
			var elemfff = frames[f].elements[0];
			if(elemfff.elementType != "instance")
			{
				fl.trace("skill no instance "+elemfff.elementType + " " + f);
			}
			else
			{
				fl.getDocumentDOM().selectNone();
				selectFrame(f);
				elemfff.selected = true;

				fl.getDocumentDOM().enterEditMode('inPlace');
				var timeline = fl.getDocumentDOM().getTimeline();
				if(timeline.layers.length > 1)
				{
					fl.trace(elemfff.libraryItem.name +" layers count > 1");
					var lllength = timeline.layers.length;
					for(var hh = 0;hh < lllength;)
					{
						var la = timeline.layers[hh];
						if(la.frames[0].elements.length <= 0)
						{
							timeline.deleteLayer(hh);
							hh--;
							lllength--;
						}
						hh++;
					}
				}
				var lay = timeline.layers[0];
				var frameLength = lay.frames.length;
				for(var i=0;i<frameLength;i++)
				{
					var fr = lay.frames[i].elements[0];
					var trans = getEffectTrans(fr);
					if(roundToTwip2(trans[0]) != 0.5)
					{
						fl.trace("transformX != 0.5 "+roundToTwip2(trans[0]));
					}
					if(roundToTwip2(trans[1]) != 0.5)
					{
						fl.trace("transformY != 0.5 "+roundToTwip2(trans[1]));
					}
					fr.setTransformationPoint({x:trans[2], y:trans[3]});
					if(maskLayer)
					{
						fr.selected = true;
						fl.trace(66666666666);
						fl.getDocumentDOM().setFillColor('#cdcdcd');
					}
					if(fr.elementType == "shape")
					{
						fl.trace(elemfff.libraryItem.name +" shape " + i);
						selectLayer(0);
						selectFrame(i);
						fl.getDocumentDOM().convertSelectionToBitmap();
					}

				}
				fl.getDocumentDOM().exitEditMode();
			}
		}
		var frame = frames[f];
		var end = frame.startFrame + frame.duration;
		if(end >= ccc)
		{
			break;
		}
		f = end;
	}
}


function getLabelXml(frames, asName) {
	var ccc = frames.length;
	for(f=0;f<ccc;f++)
	{
		frames[f].name = asName;
	}
}

function getEffectTrans(element)
{
	if(element == null)
	{
		return ["", 0, 0];
	}
	var matrix = element.matrix;
	var startX = getX(element);
	var startY = getY(element);
	var oldRot = element.rotation;
	element.rotation = 0;
	var transPoint = getTransformationPointForElement(element);

	var identityMatrix = {a:1, b:0, c:0, d:1, tx:0, ty:0};
	element.matrix = identityMatrix;

	if (element.elementType != 'text')
		setTransformationPointForElement(element, transPoint);

	var transXNormal = roundToTwip((element.transformX - element.left) / element.width);
	var transYNormal = roundToTwip(1 - (element.transformY - element.top) / element.height);
	var hX = element.width/2+element.left;
	var hY = element.height/2+element.top;
	element.matrix = matrix;

	if (element.elementType != 'text')
		setTransformationPointForElement(element, transPoint);

	setX(element, startX);
	setY(element, startY);
	element.rotation = oldRot;
	return [transXNormal, transYNormal, hX, hY];
}

function attackInfo(output)
{
	var ret = '';
	for(var i in output)
	{
		ret += i.toUpperCase() + "_ATK_POOL =\n{\n";
		for(var j in output[i])
		{
			ret += "\t["+j+"] = {";
			var first = true;
			for(var k in output[i][j])
			{
				if(!first)
				{
					ret += ", ";
				}
				else
				{
					first = false;
				}
				ret += "{";
				var ff = true;
				for(var gg = 1; gg <= j; gg++)
				{
					if(!ff)
					{
						ret += ", ";
					}
					else
					{
						ff = false;
					}
					ret += '"'+output[i][j][k]+ 'Attack' + gg + '"';
				}
				ret += "}";
			}
			ret += "}\n";
		}
		ret += "}\n"
	}
	return ret;
}

function setTransformationPointForElement(element, transPoint)
{
	var oldSelected = element.selected;
	element.selected = true;
	element.setTransformationPoint(transPoint);
	element.selected = oldSelected;
}

function selectFrame(frameIndex) {
	var dom = fl.getDocumentDOM();
	var timeline = dom.getTimeline();
	timeline.setSelectedFrames(frameIndex, frameIndex, true);
}

function selectLayer(layerIndex)
{
	var dom = fl.getDocumentDOM();
	var timeline = dom.getTimeline();
	timeline.setSelectedLayers(layerIndex, true);
}

function inArray(ar, vl)
{
	for(var i=0;i<ar.length;i++)
	{
		if(ar[i] == vl)
		{
			
			return 1;
		}
	}
	return 0;
}
function arrayMerge(ar1, ar2)
{
	var tmp = [];
	for(var i =0;i <ar1.length;i++)
	{
		if(!inArray(tmp, ar1[i]))
		{
			tmp.push(ar1[i])
		}
	}
	for(var i =0;i <ar2.length;i++)
	{
		if(!inArray(tmp, ar2[i]))
		{
			tmp.push(ar2[i])
		}
	}
	return tmp;
}  

function arrayRemove(ary, dx)  
{  
	if(isNaN(dx)||dx>ary.length){return false;}  
	for(var i=0,n=0;i<ary.length;i++)  
	{  
		if(ary[i]!=ary[dx])  
		{  
			ary[n++]=ary[i]  
		}  
	}  
	ary.length-=1  
	return ary;
} 

function objectMerge(ob1, ob2)
{
	var tmp = {};
	for(var i in ob1)
	{
		tmp[i] = ob1[i];
	}
	for(var i in ob2)
	{
		tmp[i] = ob2[i];
	}
	return tmp;
}
function stringReplace(source, find, replace)
{
	if (!source || !source.length)
		return '';
	//return source.replace(find, replace);
	return source.split(find).join(replace);
}
function roundToTwip2(value)
{
	var vv = Math.pow(10,1);
    return Math.round(value*vv)/vv;
}


function getX(element)
{
	return roundToTwip(element.transformX);
}

function getY(element)
{
	return roundToTwip(element.transformY);
}

function setX(element, x)
{
	element.transformX = x;
}

function setY(element, y)
{
	element.transformY = y;
}

function roundToTwip(value)
{
	var vv = Math.pow(10,4);
    return Math.round(value*vv)/vv;
}

function getTransformationPointForElement(element)
{
	var oldSelected = element.selected;
	element.selected = true;
	var pt = element.getTransformationPoint();
	element.selected = oldSelected;
	return pt;
}

function setTransformationPointForElement(element, transPoint)
{
	var oldSelected = element.selected;
	element.selected = true;
	element.setTransformationPoint(transPoint);
	element.selected = oldSelected;
}