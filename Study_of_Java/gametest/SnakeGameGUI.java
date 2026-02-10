import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.LinkedList;
import java.util.Random;

public class SnakeGameGUI extends JPanel implements KeyListener {
    private static final int WIDTH = 15, HEIGHT = 15, CELL_SIZE = 20;
    private LinkedList<Point> snake = new LinkedList<>();
    private Point food;
    private int direction = KeyEvent.VK_RIGHT;
    private boolean gameOver = false;

    public SnakeGameGUI() {
        setPreferredSize(new Dimension(WIDTH * CELL_SIZE, HEIGHT * CELL_SIZE));
        setBackground(Color.BLACK);
        setFocusable(true);
        addKeyListener(this);
        snake.add(new Point(WIDTH / 2, HEIGHT / 2));
        spawnFood();
        Timer timer = new Timer(150, e -> {
            if (!gameOver) move();
            repaint();
        });
        timer.start();
    }

    private void spawnFood() {
        Random rand = new Random();
        Point p;
        do {
            p = new Point(rand.nextInt(WIDTH), rand.nextInt(HEIGHT));
        } while (snake.contains(p));
        food = p;
    }

    private void move() {
        Point head = snake.getFirst();
        Point next = new Point(head.x, head.y);
        switch (direction) {
            case KeyEvent.VK_UP: next.y--; break;
            case KeyEvent.VK_DOWN: next.y++; break;
            case KeyEvent.VK_LEFT: next.x--; break;
            case KeyEvent.VK_RIGHT: next.x++; break;
        }
        if (next.x < 0 || next.x >= WIDTH || next.y < 0 || next.y >= HEIGHT || snake.contains(next)) {
            gameOver = true;
            return;
        }
        snake.addFirst(next);
        if (next.equals(food)) {
            spawnFood();
        } else {
            snake.removeLast();
        }
    }
    // 绘制游戏界面   这边有错误！！
    // @Override
    // protected void paintComponent(Graphics g) {
    //     super.paintComponent(g);
    //     g.setColor(Color.GREEN);
    //     for (Point p : snake)
    //         g.fillRect(p.x * CELL_SIZE, p.y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
    //     g.setColor(Color.RED);
    //     g.fillRect(food.x * CELL_SIZE, food.y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
    //     if (gameOver) {
    //         g.setColor(Color.WHITE);
    //         g.drawString("游戏结束！得分：" + (snake.size() - 1), 60, HEIGHT * CELL_SIZE / 2);
    //     }
    // }

    @Override
    public void keyPressed(KeyEvent e) {
        int d = e.getKeyCode();
        if ((d == KeyEvent.VK_UP && direction != KeyEvent.VK_DOWN) ||
                (d == KeyEvent.VK_DOWN && direction != KeyEvent.VK_UP) ||
                (d == KeyEvent.VK_LEFT && direction != KeyEvent.VK_RIGHT) ||
                (d == KeyEvent.VK_RIGHT && direction != KeyEvent.VK_LEFT)) {
            direction = d;
        }
    }
    public void keyReleased(KeyEvent e) {}
    public void keyTyped(KeyEvent e) {}

    public static void main(String[] args) {
        JFrame frame = new JFrame("贪吃蛇");
        SnakeGameGUI gamePanel = new SnakeGameGUI();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setContentPane(gamePanel);
        frame.pack();
        frame.setVisible(true);
        gamePanel.requestFocusInWindow();
    }
}