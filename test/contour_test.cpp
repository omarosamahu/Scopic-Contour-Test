#include <gtest/gtest.h>
#include <Contour.h>
#include <future>
#include <mutex>

using namespace Geometery;

std::mutex _mtx;
double epsilon{1e-6};
std::vector<std::shared_ptr<Countour>> getValid(const std::vector<std::shared_ptr<Countour>> &contours)
{
    std::lock_guard<std::mutex> lcm(_mtx);
    std::vector<std::shared_ptr<Countour>> valid;
    for (size_t i = 0; i < contours.size(); i++)
    {
        if (contours[i]->isValid())
        {
            valid.emplace_back(contours[i]);
        }
    }
    return valid;
}

std::vector<std::shared_ptr<Countour>> getInValid(const std::vector<std::shared_ptr<Countour>> &contours)
{
    std::lock_guard<std::mutex> lcm(_mtx);
    std::vector<std::shared_ptr<Countour>> invalid;
    for (size_t i = 0; i < contours.size(); i++)
    {
        if (!contours[i]->isValid())
        {
            invalid.emplace_back(contours[i]);
        }
    }
    return invalid;
}

std::vector<std::shared_ptr<Countour>> createContours()
{
    std::vector<std::shared_ptr<Countour>> contours;
    auto line11{std::make_shared<Shape>(Line(Point{0, 0}, Point{5, 0}))};
    auto line12{std::make_shared<Shape>(Line(Point{5, 0}, Point{5, 3}))};
    auto line13{std::make_shared<Shape>(Line(Point{5, 3}, Point{0, 3}))};
    auto line14{std::make_shared<Shape>(Line(Point{0, 3}, Point{0, 0}))};

    // Valid contours
    auto c1 = std::make_shared<Countour>(epsilon);
    c1->addSegment(line11);
    c1->addSegment(line12);
    c1->addSegment(line13);
    c1->addSegment(line14);

    contours.emplace_back(c1);

    auto line21{std::make_shared<Shape>(Line(Point{0.0, 0.0}, Point{5.0, 0.0}))};
    auto arc{std::make_shared<Shape>(Arc(Point{0.0, 0.0}, 5.0, 0.0, 180.0))};
    auto line22{std::make_shared<Shape>(Line(Point{-5.0, 0.0}, Point{0.0, 0.0}))};

    auto c2 = std::make_shared<Countour>(epsilon);
    c2->addSegment(line21);
    c2->addSegment(arc);
    c2->addSegment(line22);

    contours.emplace_back(c2);

    // Invalid contours
    auto line33 = std::make_shared<Shape>(Line({3.0, 4.0}, {1.0, 6.0}));
    auto arc23 = std::make_shared<Shape>(Arc({5.0, 2.0}, 2.0, -45.0, 0.0));

    auto c3 = std::make_shared<Countour>(epsilon);
    c3->addSegment(line33);
    c3->addSegment(arc23);
    contours.emplace_back(c3);

    auto line41{std::make_shared<Shape>(Line(Point{0.0, 0.0}, Point{5.0, 0.0}))};
    auto line42{std::make_shared<Shape>(Line(Point{5.0, 0.0}, Point{5.0, 3.0}))};
    auto line43{std::make_shared<Shape>(Line(Point{5.0, 3.0}, Point{0.0, 3.0}))};
    auto line44{std::make_shared<Shape>(Line(Point{0.1, 3.0}, Point{0.0, 0.0}))};

    auto c4 = std::make_shared<Countour>(epsilon);

    c4->addSegment(line41);
    c4->addSegment(line42);
    c4->addSegment(line43);
    c4->addSegment(line44);

    contours.emplace_back(c4);

    return contours;
}

TEST(ContourTest, HandlesInvalidContours)
{
    auto contours = createContours();
    auto f1 = std::async(std::launch::async, getValid, contours);
    auto f2 = std::async(std::launch::async, getInValid, contours);

    auto validContours = f1.get();
    auto invalidContours = f2.get();

    ASSERT_TRUE(validContours[0]->isValid());
    ASSERT_TRUE(validContours[1]->isValid());
    ASSERT_FALSE(invalidContours[0]->isValid());
    ASSERT_FALSE(invalidContours[1]->isValid());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
