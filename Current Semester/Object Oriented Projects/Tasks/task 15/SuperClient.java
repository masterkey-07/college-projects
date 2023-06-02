interface Point extends Cloneable {
    int getX();

    int getY();

    Object clone() throws CloneNotSupportedException;
}

interface Rectangle extends Cloneable {
    public Point getUpperLeft();

    public Point getLowerRight();

    Object clone() throws CloneNotSupportedException;
}

interface Triangle extends Cloneable {
    public Point getFirstPoint();

    public Point getSecondPoint();

    public Point getThirdPoint();

    Object clone() throws CloneNotSupportedException;
}

interface Circle extends Cloneable {
    public int getRadius();

    public Point getPosition();

    Object clone() throws CloneNotSupportedException;
}

class SimplePoint implements Point {
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

    private int x;
    private int y;

    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

}

class SimpleRectangle implements Rectangle {
    public Object clone() throws CloneNotSupportedException {
        SimpleRectangle cloned = (SimpleRectangle) super.clone();

        cloned.upperLeft = (Point) this.upperLeft.clone();
        cloned.lowerRight = (Point) this.lowerRight.clone();

        return cloned;
    }

    private Point upperLeft;
    private Point lowerRight;

    @Override
    public Point getUpperLeft() {
        return this.upperLeft;
    }

    @Override
    public Point getLowerRight() {
        return this.lowerRight;
    }

    public void setUpperLeft(Point upperLeft) {
        this.upperLeft = upperLeft;
    }

    public void setLowerRight(Point lowerRight) {
        this.lowerRight = lowerRight;
    }

}

class SimpleTriangle implements Triangle {
    public Object clone() throws CloneNotSupportedException {
        SimpleTriangle cloned = (SimpleTriangle) super.clone();

        cloned.firstPosition = (Point) cloned.firstPosition.clone();
        cloned.secondPosition = (Point) cloned.secondPosition.clone();
        cloned.thirdPosition = (Point) cloned.thirdPosition.clone();

        return cloned;
    }

    private Point firstPosition;
    private Point secondPosition;
    private Point thirdPosition;

    public Point getFirstPoint() {
        return this.firstPosition;
    }

    public Point getSecondPoint() {
        return this.secondPosition;
    }

    public Point getThirdPoint() {
        return this.thirdPosition;
    }

    public void setFirstPoint(Point firstPosition) {
        this.firstPosition = firstPosition;
    }

    public void setSecondPoint(Point secondPosition) {
        this.secondPosition = secondPosition;
    }

    public void setThirdPoint(Point thirdPosition) {
        this.thirdPosition = thirdPosition;
    }
}

class SimpleCircle implements Circle {
    public Object clone() throws CloneNotSupportedException {
        SimpleCircle cloned = (SimpleCircle) super.clone();

        cloned.position = (Point) this.position.clone();

        return cloned;
    }

    private int radius;
    private Point position;

    public Point getPosition() {
        return this.position;
    }

    public void setPosition(Point position) {
        this.position = position;
    }

    public int getRadius() {
        return this.radius;
    }

    public void setRadius(int radius) {
        this.radius = radius;
    }
}

class ComplexPoint implements Point {
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

    private int xy;

    public int getX() {
        return this.xy;
    }

    public int getY() {
        return this.xy;
    }

    public void setXY(int xy) {
        this.xy = xy;
    }
}

class ComplexRectangle implements Rectangle {
    public Object clone() throws CloneNotSupportedException {
        ComplexRectangle clone = (ComplexRectangle) super.clone();

        clone.upperLeft = (Point) this.upperLeft.clone();

        return clone;
    }

    private Point upperLeft;
    private int length;

    public Point getUpperLeft() {
        return this.upperLeft;
    }

    public void setUpperLeft(Point upperLeft) {
        this.upperLeft = upperLeft;
    }

    public void setLenght(int length) {
        this.length = length;
    }

    public Point getLowerRight() {
        ComplexPoint point = new ComplexPoint();

        int translate = Math.max(this.upperLeft.getX(), this.upperLeft.getY());

        point.setXY(this.length + translate);

        return point;
    }
}

class ComplexTriangle implements Triangle {
    public Object clone() throws CloneNotSupportedException {
        ComplexTriangle cloned = (ComplexTriangle) super.clone();

        cloned.firstPosition = (Point) this.firstPosition.clone();

        return cloned;
    }

    private Point firstPosition;
    private int length;

    public Point getFirstPoint() {
        return this.firstPosition;
    }

    public void setFirstPoint(Point firstPosition) {
        this.firstPosition = firstPosition;
    }

    public void setLenght(int length) {
        this.length = length;
    }

    public Point getSecondPoint() {
        SimplePoint point = new SimplePoint();
        point.setX(this.firstPosition.getX() + this.length);
        point.setY(this.firstPosition.getY());
        return point;
    }

    public Point getThirdPoint() {
        Point secondPoint = this.getSecondPoint();

        double x1 = this.firstPosition.getX();
        double y1 = this.firstPosition.getY();
        double x2 = secondPoint.getX();
        double y2 = secondPoint.getY();

        double midX = (x1 + x2) / 2.0;
        double midY = (y1 + y2) / 2.0;

        double distance = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));

        double angle = Math.atan2(y2 - y1, x2 - x1);

        double thirdX = midX + distance / 2.0 * Math.cos(angle + Math.PI / 3);
        double thirdY = midY + distance / 2.0 * Math.sin(angle + Math.PI / 3);

        SimplePoint point = new SimplePoint();

        point.setX((int) thirdX);
        point.setY((int) thirdY);

        return point;
    }
}

class ComplexCircle implements Circle {
    public Object clone() throws CloneNotSupportedException {
        ComplexCircle cloned = (ComplexCircle) super.clone();

        cloned.startPosition = (Point) this.startPosition.clone();

        return cloned;
    }

    private int length;
    private Point startPosition;

    public Point getPosition() {
        SimplePoint point = new SimplePoint();

        point.setX(this.startPosition.getX() + (this.length / 2));
        point.setY(this.startPosition.getY() + (this.length / 2));

        return point;
    }

    public int getRadius() {
        return this.length / 2;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public void setStartPosition(Point startPosition) {
        this.startPosition = startPosition;
    }
}

interface AbstractFactory {
    Point createPoint();

    Circle createCircle();

    Triangle createTriangle();

    Rectangle createRectangle();
}

class SimpleFactory implements AbstractFactory {
    public SimplePoint createPoint() {
        return new SimplePoint();
    }

    public SimpleCircle createCircle() {
        return new SimpleCircle();
    }

    public SimpleTriangle createTriangle() {
        return new SimpleTriangle();
    }

    public SimpleRectangle createRectangle() {
        return new SimpleRectangle();
    }
}

class ComplexFactory implements AbstractFactory {
    public ComplexPoint createPoint() {
        return new ComplexPoint();
    }

    public ComplexCircle createCircle() {
        return new ComplexCircle();
    }

    public ComplexTriangle createTriangle() {
        return new ComplexTriangle();
    }

    public ComplexRectangle createRectangle() {
        return new ComplexRectangle();
    }
}

public class SuperClient {
    private static boolean comparePoints(Point a, Point b) {
        return a.getX() == b.getX() && a.getY() == b.getY();
    }

    private static void testPointClone(Point a) {
        try {
            Point b = (Point) a.clone();

            System.out.println(comparePoints(a, b));
            System.out.println(a != b);
        } catch (Exception e) {
            System.out.println(false);
        }
    }

    private static void testRectangleClone(Rectangle a) {
        try {
            Rectangle b = (Rectangle) a.clone();

            boolean upperLeft = comparePoints(a.getUpperLeft(), b.getUpperLeft());
            boolean lowerRight = comparePoints(a.getLowerRight(), b.getLowerRight());

            System.out.println(upperLeft && lowerRight);
            System.out.println(a != b);
        } catch (Exception e) {
            System.out.println(false);
        }
    }

    private static void testTriangleClone(Triangle a) {
        try {
            Triangle b = (Triangle) a.clone();

            boolean firstPosition = comparePoints(a.getFirstPoint(), b.getFirstPoint());
            boolean secondPosition = comparePoints(a.getSecondPoint(), b.getSecondPoint());
            boolean thirdPosition = comparePoints(a.getThirdPoint(), b.getThirdPoint());

            System.out.println(firstPosition && secondPosition && thirdPosition);
            System.out.println(a != b);
        } catch (Exception e) {
            System.out.println(false);
        }
    }

    private static void testCircleClone(Circle a) {
        try {
            Circle b = (Circle) a.clone();

            boolean position = comparePoints(a.getPosition(), b.getPosition());
            boolean radius = a.getRadius() == b.getRadius();

            System.out.println(position && radius);
            System.out.println(a != b);
        } catch (Exception e) {
            System.out.println(false);
        }
    }

    private static void testSimpleFactory() {
        AbstractFactory simpleFactory = new SimpleFactory();

        SimplePoint pointA = (SimplePoint) simpleFactory.createPoint();
        SimplePoint pointB = (SimplePoint) simpleFactory.createPoint();
        SimplePoint pointC = (SimplePoint) simpleFactory.createPoint();

        pointA.setX(0);
        pointA.setY(0);
        pointB.setX(10);
        pointB.setY(10);
        pointC.setX(0);
        pointC.setY(10);

        SimpleRectangle rectangle = (SimpleRectangle) simpleFactory.createRectangle();

        rectangle.setUpperLeft(pointA);
        rectangle.setLowerRight(pointB);

        SimpleCircle circle = (SimpleCircle) simpleFactory.createCircle();

        circle.setPosition(pointC);
        circle.setRadius(10);

        SimpleTriangle triangle = (SimpleTriangle) simpleFactory.createTriangle();

        triangle.setFirstPoint(pointA);
        triangle.setSecondPoint(pointB);
        triangle.setThirdPoint(pointC);

        System.out.println(rectangle.getUpperLeft() == pointA);
        System.out.println(rectangle.getLowerRight() == pointB);
        System.out.println(circle.getPosition() == pointC);
        System.out.println(circle.getRadius() == 10);
        System.out.println(triangle.getFirstPoint() == pointA);
        System.out.println(triangle.getSecondPoint() == pointB);
        System.out.println(triangle.getThirdPoint() == pointC);

        testPointClone(pointA);
        testPointClone(pointB);
        testPointClone(pointC);
        testRectangleClone(rectangle);
        testTriangleClone(triangle);
        testCircleClone(circle);
    }

    private static void testComplexFactory() {
        AbstractFactory simpleFactory = new ComplexFactory();

        ComplexPoint pointA = (ComplexPoint) simpleFactory.createPoint();

        pointA.setXY(0);

        ComplexRectangle rectangle = (ComplexRectangle) simpleFactory.createRectangle();

        rectangle.setUpperLeft(pointA);
        rectangle.setLenght(10);

        ComplexCircle circle = (ComplexCircle) simpleFactory.createCircle();

        circle.setStartPosition(pointA);
        circle.setLength(10);

        ComplexTriangle triangle = (ComplexTriangle) simpleFactory.createTriangle();

        triangle.setFirstPoint(pointA);
        triangle.setLenght(10);

        System.out.println(rectangle.getUpperLeft() == pointA);
        System.out.println(rectangle.getLowerRight().getX() == 10 && rectangle.getLowerRight().getY() == 10);
        System.out.println(circle.getPosition().getX() == 5 && circle.getPosition().getY() == 5);
        System.out.println(circle.getRadius() == 5);
        System.out.println(triangle.getFirstPoint() == pointA);
        System.out.println(triangle.getSecondPoint().getX() == 10 && triangle.getSecondPoint().getY() == 0);

        testPointClone(pointA);
        testRectangleClone(rectangle);
        testTriangleClone(triangle);
        testCircleClone(circle);
    }

    public static void main(String[] args) {
        SuperClient.testSimpleFactory();
        SuperClient.testComplexFactory();
    }
}