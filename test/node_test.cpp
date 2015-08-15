#include "gtest/gtest.h"
#include "../Common/Node.h"
class NodeTest : public ::testing::Test
{
public:
	virtual void SetUp() {
		m_node_1 = Node<int>(1);
		m_node_2 = Node<int>(2);
		m_node_3 = Node<int>(3);
		m_node_1.setNext(&m_node_2);
		m_node_2.setNext(&m_node_3);
	}
	
	// virtual void TearDown();

	Node<int> m_node_1;
	Node<int> m_node_2;
	Node<int> m_node_3;
};
TEST_F(NodeTest, NodeAssignOpertor) {

	Node<int> * m_node = new Node<int>(m_node_1);
	EXPECT_EQ(m_node->getData(), m_node_1.getData() );

	Node<int> m_node_t = m_node_1;
	EXPECT_EQ(m_node_t.getData(), m_node_1.getData() );


}

TEST_F(NodeTest, NodeGetData) {
	EXPECT_EQ(m_node_1.getData(), 1);
	EXPECT_EQ(m_node_2.getData(), 2);
	EXPECT_EQ(m_node_3.getData(), 3);
}


TEST_F(NodeTest, NodeSetData) {
	Node<int> * m_node = new Node<int>(m_node_1);
	ASSERT_TRUE(m_node != NULL);

	EXPECT_EQ(m_node->getData(), m_node_1.getData() );

	m_node->setData(9);
	EXPECT_EQ(m_node->getData(), 9);

}


TEST_F(NodeTest, NodeNext) {

	// test getNext
	Node<int> *test_node = m_node_1.getNext();
	ASSERT_TRUE(test_node != NULL);

	EXPECT_EQ(test_node, &m_node_2);
	EXPECT_EQ(test_node->getData(), m_node_2.getData());


}


