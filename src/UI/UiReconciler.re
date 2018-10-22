/* Reconciler.re
 * 
 * This implements a reconciler for our UI primitives
 */

type primitives = 
    | View(Style.t)
    | Text(Style.t, string)
    | Image(Style.t, string);


type node = Node.node;

let createInstance = (prim) => {
    let node = switch (prim) {
    | View(_style) => 
        let view = new ViewNode.viewNode("test")
        view#setStyle(_style);
        view;
    | Image(style, src) => 
        let img = new ImageNode.imageNode("test", src);
        img#setStyle(style);
        img
    | Text(style, text) =>
        let text = new TextNode.textNode("test", text);
        text#setStyle(style)
        text
    };

    node
};

let appendChild = (parent: node, child: node) => {
    parent#addChild(child);
};

let removeChild = (parent: node, child: node) => {
    parent#removeChild(child);
};

let updateInstance = () => {
    print_endline ("TODO: updateElement");
};

let replaceChild = (parent: node, newChild: node, oldChild: node) => {
    removeChild(parent, oldChild);
    appendChild(parent, newChild);
    ()
};
