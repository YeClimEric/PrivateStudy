import QtQuick 2.0
import QtQuick.Particles 2.0

Rectangle {
    id: root
    width: 480; height:240
    color: "#1f1f1f"
    property bool tracer: true

    //定义粒子系统
    ParticleSystem{
        id: particleSystem
    }

    //添加两个图片画笔
    ImageParticle{
        id: rocketPainter
        system: particleSystem
        groups: ["rocket"]
        source: "qrc:/image/rocket.png"
        entryEffect: ImageParticle.Fade
    }

    ImageParticle{
        id: smokePainter
        system: particleSystem
        groups: ["smoke"]
        source: "qrc:/image/star.png"
        alpha: 0.3
        entryEffect: ImageParticle.None
    }

    //定义火箭发射器
    Emitter{
        id: rocketEmitter
        anchors.bottom: parent.bottom
        width: parent.width; height: parent.height
        system: particleSystem
        group: "rocket"
        emitRate: 5
        maximumEmitted: 10
        lifeSpan: 4800
        lifeSpanVariation: 400
        size: 32
        velocity: AngleDirection{
            angle: 270
            magnitude: 150
            magnitudeVariation: 10
        }
        acceleration: AngleDirection{
            angle: 90
            magnitude: 50
        }
        Tracer{color:"red"; visible:root.tracer}
    }

    //定义烟雾发射器
    TrailEmitter{
        id:smokeEmitter
        system: particleSystem
        emitHeight: 1
        emitWidth: 4
        group: "smoke"
        follow: "rocket"
        emitRatePerParticle: 96
        velocity: AngleDirection{
            angle: 90
            magnitude: 100
            angleVariation: 5
        }
        lifeSpan: 200
        size: 16
        sizeVariation: 4
        endSize: 0
    }
    //设置摩擦
    Friction{
        groups: ["rocket"]
        anchors.top: parent.top
        width: parent.width; height: 80
        system: particleSystem
        threshold: 5
        factor: 0.9
        Tracer{color:"yellow"; visible: root.tracer}
    }
    //设置气流
    Turbulence{
        groups: ["rocket"]
        anchors.bottom: parent.bottom
        width: parent.width; height:160
        system: particleSystem
        strength: 25
        Tracer{color:"green"; visible: root.tracer}

    }

}
