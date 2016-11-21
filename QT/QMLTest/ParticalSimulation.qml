import QtQuick 2.0
import QtQuick.Particles 2.0
/*
    粒子系统模拟
*/

Rectangle {
    id:root
    width:480; height:160
    color:"#1f1f1f"

    ParticleSystem {
        id: particleSystem
    }

    Emitter{
        id:emitter
        x:0; y:parent.height / 2
        //anchors.centerIn: parent
        system:particleSystem
        width:2; height:2
        emitRate: 5
        lifeSpan: 6400
        lifeSpanVariation: 400
        size:16
        endSize: 32

        //设置方向矢量空间
        velocity: TargetDirection{
            targetX: 1000
            targetY: 0
            targetVariation: 10
            magnitude: 100
        }

        //设置点矢量空间
        //velocity: PointDirection{
        //    x:100
        //    y:0
        //    xVariation: 0
        //    yVariation: 100 / 6
        //}

        //设置角度矢量空间，控制粒子的方向和速度
        //velocity: AngleDirection{
        //    angle: -45
        //    //angleVariation: 15
        //
        //    magnitude: 100
        //    //magnitudeVariation: 50
        //}
        acceleration: AngleDirection{
            angle: -90
            magnitude: 10
        }


    }
    //可以叠加粒子
    //ImageParticle{
    //    source: "qrc:/image/pinwheel.png"
    //    system: particleSystem
    //}
    ImageParticle{
        source: "qrc:/image/star.png"
        system: particleSystem

        color:"#ffd700"
        colorVariation: 0.2

        rotation: 15 //顺时针旋转15°
        rotationVariation: 5 //角度在±5°范围变化
        rotationVelocity: 45 //每个粒子会不断的以45°/s旋转
        rotationVelocityVariation: 15 // 每个粒子的旋转速度在±15°之间变化
        entryEffect: ImageParticle.Scale
    }

    //ItemParticle{
    //    id:itemParticle
    //    system: particleSystem
    //    delegate: Button
    //}

    //控制粒子的衰减
    //Age {
    //    anchors.horizontalCenter: parent.horizontalCenter
    //    width: 240; height: 120
    //    system: particleSystem
    //    advancePosition: true
    //    lifeLeft: 5000
    //    once: true
    //}
    //控制粒子的摩擦，减慢粒子的运动
    Friction {
        anchors.horizontalCenter: parent.horizontalCenter
        width: 240; height: 120
        system: particleSystem
        factor : 0.8
        threshold: 25

        Tracer{}
   }
}
