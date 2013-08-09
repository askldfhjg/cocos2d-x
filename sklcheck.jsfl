
var file = fl.configURI + 'Commands/json2.jsfl';
fl.runScript(file); 

var boneName = ["fronthand",
				"frontshoulder",
				"weapon",
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
				"backhair"];
var actionList = {};
var spriteList = {};
var exportPng = [];
var startFrameStatus = {};
var startIndex = 0;
var select = fl.getDocumentDOM().selection;
var lll = select.length;
fl.showIdleMessage(false);
for(var i =0;i < lll;i++)
{
	var elem = select[i];
	fl.trace(elem.libraryItem.name)
	setTransformationPointForElement(elem, {x:0, y:0});
	fl.getDocumentDOM().selectNone();
	elem.selected = true;
	document.enterEditMode('inPlace');
	var asName = elem.libraryItem.linkageClassName;
	getActionList(boneName, asName);
	document.exitEditMode();
	fl.trace("-------------------------------------");
}
fl.showIdleMessage(true);

function getActionList(boneName, asName)
{
	var timeline = fl.getDocumentDOM().getTimeline();
	var layers = timeline.layers;
	var labelEnd = 0;
	var maxFrameId = 0;
	var boneOtherLayer = 1;
	var labelLayer = null;
	for(var layerIndex = 0; layerIndex < layers.length; layerIndex++) {
		var currentLayer = layers[layerIndex];
		var name = currentLayer.name.toLowerCase();
		if(!currentLayer.visible) {
			if(inArray(boneName, name))
			{
				fl.trace(asName+" "+name+" 不可见");
				currentLayer.visible = true;
			}
			continue;
		}
		var frames = currentLayer.frames;
		if(currentLayer.name.toLowerCase() == "label") {
			timeline.setSelectedLayers(layerIndex, true);
			timeline.clearKeyframes(0, frames.length - 1);
			frames = currentLayer.frames;
			getLabelXml(frames, asName);
			labelEnd = frames.length - 1;
			labelLayer = layerIndex;
			continue;
		}
		if(currentLayer.name.toLowerCase() == "shadow") {
			continue;
		}
		if(!inArray(boneName, name))
		{
			currentLayer.name = asName + "skill" + boneOtherLayer;
			
			if(name.toLowerCase().lastIndexOf("attacklayer") != -1)
			{
				getFrameXML(labelLayer, currentLayer, asName);
				currentLayer.name = asName + "attacklayer" + boneOtherLayer;
			}
			boneOtherLayer++;
		}
		maxFrameId = frames.length - 1;
	}
	if(maxFrameId > labelEnd)
	{
		fl.trace(asName+" label 少了");
	}
}

function getFrameXML(labelLayerId, currentLayer, asName) {

	var frames = currentLayer.frames;
	var ccc = frames.length;
	var flag = false;
	var keyframe = [];
	if(frames[0].elements.length >0)
	{
		flag = true;
		keyframe.push(0);
	}
	for(f=0;f<ccc;)
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
			keyframe.push(end);
		}
		f = end
	}
	var timeline = fl.getDocumentDOM().getTimeline();
	timeline.setSelectedLayers(labelLayerId, true);
	var labelLayer = timeline.layers[labelLayerId];
	var labelframes = labelLayer.frames;
	for(var i = 0; i < keyframe.length; i++)
	{
		//timeline.convertToKeyframes(keyframe[i]);
	}
	labelframes = labelLayer.frames;
	for(var i = 0; i < keyframe.length; i++)
	{
		//labelframes[keyframe[i]].name = asName + "Hit" + (i+1);
	}
}


function getLabelXml(frames, asName) {
	var ccc = frames.length;
	for(f=0;f<ccc;f++)
	{
		frames[f].name = asName;
	}
}


function setTransformationPointForElement(element, transPoint)
{
	var oldSelected = element.selected;
	element.selected = true;
	element.setTransformationPoint(transPoint);
	element.selected = oldSelected;
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
