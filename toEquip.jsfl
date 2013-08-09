/*var timeline = fl.getDocumentDOM().getTimeline();
var layer = timeline.layers[0];
var elem= layer.frames[0].elements;
for (var i = elem.length - 1; i >= 0; i--) {
	if(elem[i].name == 'mcGenderBox')
	{
		fl.getDocumentDOM().selectNone();
		elem[i].selected = true;
		document.enterEditMode('inPlace');
	}
};*/

fl.getDocumentDOM().setTransformationPoint({x:0, y:0});

var file = fl.configURI + 'Commands/json2.jsfl';
fl.runScript(file); 
var fm = fl.getDocumentDOM().getTimeline().layers[0].frames[0];

var elem = fm.elements[0];
var xOffset = elem.transformX - elem.x;
var yOffset = elem.transformY - elem.y;
fl.getDocumentDOM().selectNone();
elem.selected = true;
document.enterEditMode('inPlace');
getActionList(0);
document.exitEditMode();
function getActionList(startIndex)
{
	var spriteList = {};
	var exportPng = [];
	var timeline = fl.getDocumentDOM().getTimeline();
	var layers = timeline.layers;
	for(var layerIndex = 0; layerIndex < layers.length; layerIndex++) {
		var currentLayer = layers[layerIndex];
		if(!currentLayer.visible || currentLayer.frames.length <= 0) {
			continue
		}
		var frames = currentLayer.frames;
		if(currentLayer.name.toLowerCase() == "label") {
			continue;
		}
		selectLayer(layerIndex);
		selectFrame(0);
		var currentFrame = frames[0];
		var tmp = getSourceXML(currentFrame.elements[0], currentLayer.name.toLowerCase(), spriteList, exportPng);
		spriteList = tmp['spriteList'];
		exportPng = tmp['exportPng'];
	}
	saveMotionXML(exportPng, spriteList);
}

function getSourceXML(element, layerName, spriteList, exportPng){

	var matrix = element.matrix;
	var scaleXStart = getMatrixScaleX(matrix);
	var scaleYStart = getMatrixScaleY(matrix);
	var skewXStart = getMatrixSkewX(matrix);
	var skewYStart = getMatrixSkewY(matrix);
	var libraryItem = element.libraryItem;
	if (libraryItem) {
		exportPng.push(libraryItem);
	}
	var name = element.libraryItem.name.split('/');

	var orgPoint = getTransformationPointForElement(element);
	setTransformationPointForElement(element, {x:0, y:0});
	fl.trace(orgPoint.x);
	var startX = getX(element);
	var startY = getY(element);
	
	var transPoint = getTransformationPointForElement(element);

	var identityMatrix = {a:1, b:0, c:0, d:1, tx:0, ty:0};
	element.matrix = identityMatrix;

	if (element.elementType != 'text')
		setTransformationPointForElement(element, transPoint);

	var leftOffset = roundToTwip((element.transformX - element.left));
	var topOffset = roundToTwip((element.transformY - element.top)); 
	element.matrix = matrix;

	if (element.elementType != 'text')
		setTransformationPointForElement(element, transPoint);

	setX(element, startX);
	setY(element, startY);

	setTransformationPointForElement(element, orgPoint);
	spriteList[layerName] = [name[name.length - 1]+"0000", scaleXStart, scaleYStart, leftOffset, topOffset];
	return {"exportPng":exportPng, "spriteList":spriteList};
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

function getMatrixScaleX(matrix)
{
	var angleYRad = Math.atan2(matrix.b, matrix.a);
	var cos = Math.cos(angleYRad);
	var scaleX = matrix.a / cos;
	if (Math.abs(cos) < 1e-12)
		scaleX = matrix.b / Math.sin(angleYRad);
	var scaleRound = 1000;
	scaleX = Math.round(scaleX*scaleRound)/scaleRound;
	return scaleX;
}

function getMatrixScaleY(matrix)
{
	var angleXRad = Math.atan2(-matrix.c, matrix.d);
	var cos = Math.cos(angleXRad);
	var scaleY = matrix.d / cos;
	if (Math.abs(cos) < 1e-12)
		scaleY = -matrix.c / Math.sin(angleXRad);
	var scaleRound = 1000;
	scaleY = Math.round(scaleY*scaleRound)/scaleRound;
	return scaleY;
}

function getMatrixSkewX(matrix)
{
	var angleXRad = Math.atan2(-matrix.c, matrix.d);
	var angleRound = 10;
	var angleX = Math.round(angleXRad * 180/Math.PI * angleRound)/angleRound;
	return angleX;
}

function getMatrixSkewY(matrix)
{
	var angleYRad = Math.atan2(matrix.b, matrix.a);
	var angleRound = 10;
	var angleY = Math.round(angleYRad * 180/Math.PI * angleRound)/angleRound;
	return angleY;
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

function inArray(ar, vl)
{
	for(i=0;i<ar.length;i++)
	{
		if(ar[i] == vl)
		{
			return 1;
		}
	}
	return 0;
}
function stringReplace(source, find, replace)
{
	if (!source || !source.length)
		return '';
	//return source.replace(find, replace);
	return source.split(find).join(replace);
}

function saveMotionXML(png, sprite)
{
	var fileURL = fl.browseForFolderURL("save", "fffffff");
	if (!fileURL || !fileURL.length) {
		return false;
	}
	if(fileURL.charAt(fileURL.length-1) != '/')
	{
		fileURL += '/';
	}

	var exporter = new SpriteSheetExporter; 
	exporter.beginExport();
	exporter.autoSize = true;
	exporter.allowTrimming = true;
	exporter.allowRotate = false;
	exporter.shapePadding = 2;
	exporter.algorithm = "maxRects";
	exporter.layoutFormat = "cocos2D v3";
	exporter.format = "RGBA8888";

	var index = 0;
	for (var j = 0; j < png.length; j++) {
	        exporter.addSymbol(png[j]);
	        fl.trace(png[j].name);
	}
	
	var name = fl.getDocumentDOM().name.split(".")[0];
	exporter.exportSpriteSheet(fileURL+"pic/"+name,{format:"png", bitDepth:32, backgroundColor:"#00000000"});
	sprite['picture'] = name;
	//var ret = '{"bone":'+JSON.stringify(sprite)+', "motion":'+JSON.stringify(contents)+'}';
	if (!FLfile.write(fileURL+name+".equip", JSON.stringify(sprite)))
	{
		alert(CopyMotionErrorStrings.SAVE_ERROR);
		return false;
	}
	return true;
}
