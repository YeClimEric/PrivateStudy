import QtQuick 2.0

Canvas {
    id:root
    width: 240; height:120
    onPaint: {
        var ctx = getContext("2d")
        ctx.strokeStyle = "blue"
        ctx.lineWidth = 4
        ctx.beginPath()
        ctx.rect(20, 20, 60, 60)
        ctx.translate(120, 60)
        ctx.stroke()

        ctx.strokeStyle = "green"
        ctx.rotate(Math.PI / 4)
        ctx.stroke()
    }

}
